'use strict';
const fs = require('fs');

function readFile(fileName) { // readFile関数の作成
    return new Promise( // Promise:非同期処理の完了(もしくは失敗)の結果及びその結果の値を返す.
        (onFulfilled, onRejected)=>{
            //NodeモジュールreadFileの呼び出し readFile(ファイルのパス, 文字コード, コールバック関数)
            fs.readFile(fileName, "utf-8", (err, data)=>{
                // アロー関数の中
                console.log(data);
                if (err) { // ファイルの読み込みに失敗した場合のコールバック関数err{}
                    console.error("readFile error:" + fileName + err);
                    onRejected(err); // 失敗のエラーを返す
                }
                onFulfilled(data); // ファイルの読み込みに成功:ファイルの中身を返す
            }); // アロー関数終了
        }
    );
}

function writeFile(fileName, data) { //writeFile関数の作成
    return new Promise( // 非同期処理の完了(もしくは失敗)の結果及びその結果の値を返す.
        (onFulfilled, onRejected)=> { //アロー関数の始まり
            // NodeモジュールwriteFileの呼び出し writeFile(ファイルのパス, 書き込む文字, コールバック関数)
            fs.writeFile(fileName, data, err=>{ 
                if (err) { // 書き込み失敗した場合のPromiseのコールバック関数
                    console.error("writeFile error:" + fileName + err);
                    onRejected(err);
                }
                onFulfilled("OK"); // 書き込み成功した場合のPromise
            });
        } // アロー関数の終了
    );
}

let allData = "";
readFile("a.txt") // 作成したreadFileの呼び出し: 引数にa.txt
// then method : 最大2つの引数, Promiseが成功した場合と失敗した場合のコールバック関数
.then(function(fileData) { // Promiseに成功した場合ファイルの中身を取得
    allData += fileData; // 空文字列に読み込んだファイルの中身を追加
    return readFile("b.txt"); // プロミスを返してチェイニング可能にする 
    // チェイニング(chaining): ひとつのプロミスが成功したら, すぐにプロミスを返す関数を起動する 
})
.then(function(fileData) {
    allData += fileData; 
    // 上記のreturn readFile("b.txt")でデータの読み込み成功している場合, 
    // "b.txt"のファイルの中身をallDataに追加する
    return readFile("c.txt"); // 上記と同様にプロミスを返してチェイニング可能にする
})
.then(function(fileData) {
    allData += fileData;
    return writeFile("d.txt", allData); // writeFile関数の呼び出し
    //Promiseが成功した場合, readFileで読み込んだallDataがd.txtに書き込まれる
})
.then(function(mes) {
    console.log("ファイルの合体に成功しました.");
})
.catch(err => {
    // Promiseが失敗した場合
    console.error("エラーが起こりました:" + err);
});
