/*
 * @Author: Payne
 * @Date: 2021-03-08 17:16:34
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-09 14:22:11
 * @Description: 
 */
use tokio::net::{TcpListener, TcpStream};
use mini_redis::{Connection, Frame};

#[tokio::main]
async fn main() {
    // 绑定监听器到一个地址
    let mut listener = TcpListener::bind("127.0.0.1:6379").await.unwrap();

    loop {
        // 第二项包含新链接的IP与端口
        let (socket, _) = listener.accept().await.unwrap();
        tokio::spawn(async move {
            process(socket).await;
        });
    }
}

async fn process(socket: TcpStream) {
    // "链接" 可以让我们通过字节流 读/写 redis的 **帧**. "链接" 类型被 mini-redis 定义.
    let mut connection = Connection::new(socket);

    if let Some(frame) = connection.read_frame().await.unwrap() {
        println!("GOT: {:?}", frame);

        // 响应一个错误
        let response = Frame::Error("unimplemented".to_string());
        connection.write_frame(&response).await.unwrap();
    }
}