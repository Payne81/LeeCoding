/*
 * @Author: Payne
 * @Date: 2021-01-18 15:51:50
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-04 17:43:09
 * @Description: 
 */
#![allow(dead_code)]

/**
 *  scope:  路由前缀
 *  State:  State被同一作用域(Scope)内的所有路由和资源共享.
            用web::Data<T> 来访问，其中 T 是 state的类型. State也能被中间件访问.
 */

use actix_web::{get, web, App, HttpServer};

// 这个结构体代表一个State
struct AppState {
    app_name: String,
}

#[get("/")]
async fn index(data: web::Data<AppState>) -> String {
    let app_name = &data.app_name; // <- 得到app名

    format!("Hello {}!", app_name) // <- 响应app名
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .data(AppState {
                app_name: String::from("Actix-web"),
            })
            .service(
                web::scope("/app")
                // ...因此handler的请求是对应 `GET /app/index.html`
                .route("/index.html", web::get().to(index)),
            )
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}