# I/Oモデル

- Synchronous I/O (同期 I/O)
    - blocking I/O(ブロッキングI/O)
    - non-blocking I/O(非ブロッキングI/O)
    - I/O multiplexing(I/O多重化)
    - signal driven I/O(シグナル駆動I/O)

- Asynchronous I/O (非同期 I/O)
    - Asynchronous(非同期I/O)

## C10K 問題
ハードウェアの性能上は問題がなくても、あまりにもクライアントの数が多くなるとサーバがパンクする問題のこと

### 解決方法
- 1. 各スレッドが複数のクライアントを受け付ける。 そしてノンブロッキン グ I/O  と レベル・トリガ型の完了通知 (level­triggered readiness  notification) を利用する。
- 2. 各スレッドが複数のクライアントを受け付ける。 そしてノンブロッキン グ I/O  と 変更型の完了通知 (readiness change notification) を利 用する。
- 3. 各スレッドが複数のクライアントを受けつける。そして非同期 I/O  を 使う。
- 4. 各スレッドが一つのクライアントを受けつける。そしてブロッキング I/O  を使う。
- 5. サーバのコードをカーネルに組込む

## 「libev」と「libeio」を利用して、非同期I/O環境を実装

### libev
C言語製のイベントループライブラリ
- イベントループとは、無限ループを行いながら、I/O を監視し、利用可能やI/O 完了等のイベントが発生するとコールバック（または、シグナル）により通知。
- I/O の監視には、I/O multiplexing(I/O多重化)モデルを使用し、環境によって最適なシステムコール（Linux であればepoll,FreeBSDではkqueueを使用。

### libeio
C言語製の非同期I/Oライブラリ
-  実装的にはキューとスレッドプールを使い、I/O を非同期並行処理する。

### Node.jsのアーキテクチャ

```
|----------------------------------------------------------------------------|
|                           Node Standard Library                            |
|----------------------------------------------------------------------------|
|                           Node Bindings                                    |
|                           (socket,http,etc)                                |
-----------------------------------------------------------------------------|
|      V8     |   thread poll   |   event loop  |   DNS    |   http parser   |
|             |     (libeio)    |     (libev)   | (c-ares) |                 |
|----------------------------------------------------------------------------|
```


### 参考資料
- [Node.js入門](https://www.slideshare.net/forest1040/nodejs-7658878)
- [Aio](https://www.slideshare.net/hirose31/aio)
- [(簡単実装で学ぶWeb技術) 第2回 Comet---プッシュ型のWebアプリケーションを作る](https://tech.nikkeibp.co.jp/it/article/COLUMN/20080220/294242/)
- [(簡単実装で学ぶWeb技術) 第3回 Cookie---状態管理とトラッキング](https://tech.nikkeibp.co.jp/it/article/COLUMN/20080331/297574/)
- [epoll を使った echo サーバ](https://odz.hatenablog.com/entry/20070507/1178558340)
- [[C言語] libevでechoサーバを作る](http://d.hatena.ne.jp/winebarrel/20080309/p2)
- [node.js のソースぐらい読んでおきたい！](http://d.hatena.ne.jp/edvakf/20101207/1291556433)
