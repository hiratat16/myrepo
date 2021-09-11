//プロトタイプを理解する

//prototypeプロパティ
//①コンストラクタ関数（オブジェクトに使われる関数）を定義
function Human(name) {
    this.name = name;
}
//②prototypeを拡張
//prototypeプロパティを使って,Humanにgreetメソッドを追加
Human.prototype.greet = function() {
    console.log("Hello " + this.name);
}

//③ インスタンス：②のメソッドを使用する時は,new演算子でオブジェクトを生成する.
var mike = new Human("Mike");
mike.greet(); // Hello Mike

//プロトタイプチェーン：__ptoto__プロパティに入っている別のオブジェクトから連鎖的に探す
//prototypeプロパティ：オブジェクト生成の時に使用
//__proto__プロパティ：プロトタイプチェーンで探していく時に使用


/*--------------------------------------------------------*/
//プロトタイプを使ったメモリの制約

function Human(name) {
    this.name = name;
    //コンストラクタでメソッドを追加
    this.greet = function() {
        console.log("My name is " + this.name);
    };
}

var alice = new Human("Alice");
alice.greet(); //My name is Alice

var bob = new Human("Bob");
bob.greet(); //My name is Bob

//好ましくないコード：インスタンスの数だけメモリを確保している


/*--------------------------------------------------------*/
function Human(name) {
    this.name = name;
}

//greetメソッドはメモリーにコピーされず,「Human.prototype.greet」を参照する
//インスタンス生成の際に確保されるメモリはnameのみ
Human.prototype.greet = function () {
    console.log("My name is " + this.name);
};

var alice = new Human("Alice");
alice.greet();

var bob = new Human("Bob");
bob.greet();

