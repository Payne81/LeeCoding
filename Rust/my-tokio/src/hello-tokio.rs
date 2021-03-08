/*
 * @Author: Payne
 * @Date: 2021-03-08 17:17:59
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-08 17:18:16
 * @Description: 
 */
#![allow(dead_code)]
use mini_redis::{client, Result};

#[tokio::main]
pub async fn main() -> Result<()> {
    // 打开链接到mini-redis的链接
    let mut client = client::connect("127.0.0.1:6379").await?;

    // 设置 "hello" 键的值为 "world"
    client.set("hello", "world".into()).await?;

    // 获取"hello"的值
    let result = client.get("hello").await?;

    println!("got value from the server; result={:?}", result);

    Ok(())
}