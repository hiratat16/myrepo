//クロージャを理解する
/*------------------------------------------------------------------*/
//変数のスコープ

var a = 10;
function add() {
    var b = 5;
    console.log(a + b);
}

add(); //15
console.log(a + b); //Uncaught ReferenceError: b is not defined

/*------------------------------------------------------------------*/
var a = 10;
var b = 15;
function add(){
    a = 5;
    var b = 5;
    console.log(a + b);
}

add(); // 10
//var無し→グローバルスコープを参照
console.log(a); 5
//var有り→ローカルスコープ参照
console.log.apply(b); 15

/*------------------------------------------------------------------*/
//クロージャ：実行時の環境ではなく,変数自身が定義された環境が保持される
// クロージャーを使わない例①

var count = 0;
function counter() {
    count++;
    console.log(count);
}

counter(); //1
counter(); //2

/*------------------------------------------------------------------*/
// クロージャーを使わない例②

var count1 = 0;
function counter1() {
    count1++;
    counsole.log(count1);
}

var count2 = 0;
function counter2() {
    count2++;
    console.log(count2);
}

counter1(); //1
counter1(); //2
counter2(); //1
counter2(); //2

// 保守性の問題,グローバル変数なので書き換えられる
count1 = 100;

counter1(); //101
counter1(); //102

/*------------------------------------------------------------------*/
// クロージャーを使う例

function createCounter() {
    var count = 0;
    return function() {
        count++;
        console.log(count);
    }
}

var counter1 = createCouter();
counter1(); //1
counter1(); //2
counter1(); //3

var counter2 = createCouter();
counter2(); //1
counter2(); //2

count = 100;

counter1(); //4