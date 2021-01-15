
// 共享可变状态(Shared Mutable State)
use actix_web::{web, App, HttpServer};
use std::sync::Mutex;

struct AppStateWithCounter {
    counter: Mutex<i32>, // <- Mutex 必须安全的在线程之间可变
}

async fn index(data: web::Data<AppStateWithCounter>) -> String {
    let mut counter = data.counter.lock().unwrap(); // <- 得到 counter's MutexGuard
    *counter += 1; // <- 在 MutexGuard 内访问 counter

    format!("Request number: {}", counter) // <- 响应counter值
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let counter = web::Data::new(AppStateWithCounter {
        counter: Mutex::new(0),
    });

    HttpServer::new(move || {
        // 移动 counter 进闭包中
        App::new()
            // !!注意这里使用 .app_data 代替 data
            .app_data(counter.clone()) // <- 注册创建的data
            .route("/", web::get().to(index))
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}