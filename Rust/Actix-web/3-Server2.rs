use actix_web::{web, App, HttpResponse, HttpServer, rt::System};
use std::sync::mpsc;
use std::thread;

#[actix_web::main]
async fn main() {
        let (tx, rx) = mpsc::channel();

            thread::spawn(move || {
                        let sys = System::new("http-server");

                                let srv = HttpServer::new(|| {
                                                App::new().route("/", web::get().to(|| HttpResponse::Ok()))
                                                            })
                                        .bind("127.0.0.1:8080")?
                                                    .shutdown_timeout(60) // <- 设置关机超时时间为60s.
                                                            .run();

                                                let _ = tx.send(srv);
                                                        sys.run()
                                                                });

                let srv = rx.recv().unwrap();

                    // 暂停接收新的链接
                    //     srv.pause().await;
                    //         // 继续接收新的链接
                    //             srv.resume().await;
                    //                 // 停止服务
                    //                     srv.stop(true).await;
                    //                     }
