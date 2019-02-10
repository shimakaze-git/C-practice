#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>

/*
    param msg(const, str: pointer)
*/
static void die(const char* msg){
    /*
        perror()
        エラー番号に対応するエラーメッセージを標準エラー出力。

        msgを標準エラー出力
    */
    perror(msg);

    /*
        exit()
        プログラムの終了

        EXIT_FAILURE : 失敗終了状態
    */
    exit(EXIT_FAILURE);
}


static void set_nonblocking(int sock){
    /*
        fcntl()
        ファイルディスクリプタの操作を行う

        fcntl(int fd, int cmd, long arg)
        fd: オープンされたファイルディスクリプタ
        cmd: F_GETFL(ファイル状態フラグを読み出す。)
        arg: ファイル状態フラグに arg で指定された値を設定
    */
    int flag = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flag | O_NONBLOCK);
}