use actix_web::{web, App, HttpServer, guard, HttpResponse, Responder};


// guard 过滤掉一些HTTP请求
#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .service(
                web::scope("/")
                    .guard(guard::Header("Host", "www.rust-lang.org"))
                    .route("", web::to(|| HttpResponse::Ok().body("www"))),
            )
            .service(
                web::scope("/")
                    .guard(guard::Header("Host", "users.rust-lang.org"))
                    .route("", web::to(|| HttpResponse::Ok().body("user"))),
            )
            .route("/", web::to(|| HttpResponse::Ok().body("route ok")))
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}