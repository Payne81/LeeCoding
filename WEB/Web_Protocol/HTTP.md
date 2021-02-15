# HTTP

1. 使用TCP

2. 无状态协议

3. 80端口

## 非持续连接和持续连接

1. HTTP默认使用持续连接，但HTTP客户端和服务器端也能配置成使用非持续连接。

2. 非持续连接每个连接只发送一个对象，每个对象要经受两倍RTT交付时延。

3. 现代浏览器可以配置非持续连接保持几个连接并行处理。

## HTTP请求报文

1. 请求行: 方法|URL|版本

2. 首部行

3. 空行

4. 实体主体

#### GET

无实体主体，可以通过url提交表单

#### POST

有实体主体

#### HEAD

服务端收到HEAD请求后会响应一个没有请求对象的报文，常用于调试跟踪。

#### PUT&DELETE

增加&删除服务端内容

## HTTP响应报文

1. 状态行: 版本|状态码|状态信息

2. 首部行

3. 空行实体

4. 实体

#### 200

#### 300

#### 400

## Cookie

![https://upload-images.jianshu.io/upload_images/13949989-dcf024be2733e725.png](https://upload-images.jianshu.io/upload_images/13949989-dcf024be2733e725.png)

##### Cookie属性:

1. name = value

2. Expires: 过期时间

3. Domain: 生成该Cookie的域名，Cookie无法跨域名

4. Path: 访问该路径时才会访问此Cookie/该 Cookie 是在当前的哪个路径下生成的，如 path=/wp-admin/

5. Secure: 如果设置了这个属性，这个cookie只能用https协议发送给服务器（用https设置的Cookie）

## Web缓存(代理服务器)

主要关注HTTP代理

### 应用层代理

主要是**HTTP代理**，也有FTP代理

### 传输层代理

直接与TCP层交互

## 条件GET方法

1. 请求报文使用了GET方法 

2. 请求报文包括了一个If-Modified-Since首部行

当代理服务器向Web服务器发送条件GET时，如果无修改，回响应304:

```http
HTTP/1.1 304 Not Modified 
Date: Sat, 15 Oct 2011 15:39:29 
Server: Apache/1.3.0 (Unix)

(empty entity body)
```

否则会返回对象
