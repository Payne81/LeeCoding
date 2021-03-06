/*
 * @Author: Payne
 * @Date: 2021-01-18 15:51:50
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-04 17:42:48
 * @Description: 
 */
#![allow(dead_code)]

use actix_web::{get, post, web, App, HttpResponse, HttpServer, Responder};

/** async函数声明
  * Http请求/响应(Responder)     
  */
#[get("/")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().body("Hello world!")
}

#[post("/echo")]
async fn echo(req_body: String) -> impl Responder {
    HttpResponse::Ok().body(req_body)
}

async fn manual_hello() -> impl Responder {
    HttpResponse::Ok().body("Hey there!")
}

// 返回类型：std::io::Result<()>
#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .service(hello)
            .service(echo)
            .route("/hey", web::get().to(manual_hello))
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}