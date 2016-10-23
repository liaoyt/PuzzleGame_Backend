#PuzzleGame_Backend

###3.27
* 更新java中使用的样例，注意这些网络操作都不能在主线程做，用android的异步或者java新线程都可以
* 下面是登陆的示例
```java
	// 连接
            try {
                clientSocket = new Socket(host, port);
            } catch (UnknownHostException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            // 构造请求
             request = ProtobufUtils.PGRequest.newBuilder()
                    .setCode("1").setUsername("lisi").setPassword("222222").build();

            // 获取输入输出流并发送请求
            try {
                inputStream = clientSocket.getInputStream();
                outputStream = clientSocket.getOutputStream();
                outputStream.write(request.toByteArray());
            } catch (IOException e) {
                e.printStackTrace();
            }

            // 接受消息
            byte[] buf = new byte[1024];
            int len = 0;
            try {
                len = inputStream.read(buf);
                byte[] data = new byte[len];
                for (int i = 0; i<len; i++)
                    data[i] = buf[i];
                request = ProtobufUtils.PGRequest.parseFrom(data);
            } catch (IOException e) {
                e.printStackTrace();
            }

            // 关闭流和套接字
            try {
                inputStream.close();
                outputStream.close();
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
```

###3.26
* 完成了所以功能

###3.21
* 再调整了整体的结构
* 完成了用户注册和登陆的接口


###3.20
* 简单写了一个protobuf，暂时考虑的数据只有这些
* 拿原先的server和client的代码去掉了不相关的内容，目前可以跑起来，还没有任何相关的交互。
