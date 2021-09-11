//thisを理解する
//「関数が呼ばれたときに,その関数が属しているオブジェクト」を指す.
function Human(name) {
    this.name = name;
};
Human.prototype.greet = function() {
    console.log("Hello " + this.name);
}
var mike = new Human("Mike");
mike.greet();

/*----------------------------------------------------------------*/
//関数の呼び出しのとき,thisは何を指すのか?
function greet() {
    console.log("Hello " + this.name);
}
greet();

/*
コンソールでthisを呼び出した結果
this
Window {window: Window, self: Window, document: document, name: '', location: Location, …}
*/

/*----------------------------------------------------------------*/
/*thisを操作（束縛）する
・all(object, arg1, arg2, ...)
・apply(object, Array)
・bind(object, arg1, arg2, ...)
callメソッドとapplyメソッドは,関数をすぐに実行する.（第2引数が違うだけ）
*/

//callメソッド
function Human(name) {
    this.name = name;
}
function greet(arg1, arg2) {
console.log(arg1 + this.name + arg2);
}
var mike = new Human("Mike");
//第1引数のmikeをthisとして実行し,第2引数以降が関数greetの引数になる
greet.call(mike, "Hello ", "!!");

/*----------------------------------------------------------------*/
//applyメソッド
function Human(name) {
    this.name = name;
}
function greet(arg1, arg2) {
console.log(arg1 + this.name + arg2);
}
var mike = new Human("Mike");
//第1引数のmikeをthisとして実行し,第2引数の配列が関数greetの引数になる
greet.apply(mike, ["Hello ", "!!"]);


/*----------------------------------------------------------------*/
//bindメソッド
//呼び出されたときに新しい関数を生成し,値を束縛する
function Human(name) {
    this.name = name;
}
function greet(arg1, arg2) {
console.log(arg1 + this.name + arg2);
}
var mike = new Human("Mike");
//mikeをthisに束縛した新しい関数を返す
var greetMorning = greet.bind(mike);
//関数greetMorningの呼び出し時は常にmikeがthisとなる.
greetMorning("Good Morning ", "!!");