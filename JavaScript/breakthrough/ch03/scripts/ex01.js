/* パーティクルを描いて動かす */

//canvas要素の取得
var canvas = document.getElementById( "canvas" );
//canvas要素から描画コンテキストの取得
var ctx = canvas.getContext( "2d" );

/* 図形を描く */
// // パスを初期化
// ctx.beginPath();
// //色を指定
// ctx.fillStyle = "#99ff66";
// //長方形を描画
// ctx.rect( 0, 0, 100, 200 );
// //塗り潰し
// ctx.fill();
// //パスを閉じる
// ctx.closePath();

/* fillstyleプロパティ 
ctx.fillStyle = "red";
ctx.fillStyle = "#ff0000";
ctx.fillStyle = "rgb(255, 0, 0)";
ctx.fillStyle = "rgba(255, 0, 0, 0.6)";
*/


/* 円を描く */
// ctx.beginPath();
// ctx.fillStyle = "#99ff66";
// //ctx.arc( x座標, y座標, 半径, 角度 )
// ctx.arc( 100, 100, 40, 0, Math.PI * 2 );
// ctx.fill();
// ctx.closePath();

/* 円を動かす 
    1. 図形を描画
    2. 一度図形を消去
    3. 位置をずらす
    4. 再度図形を描画
    5. 一定時間を置く
*/

// var interval = Math.floor(1000/60);

// function draw() {
//     ctx.beginPath();
//     ctx.fillStyle = "#99ff66";
//     ctx.rect( 0, 0, 100, 200 );
//     ctx.fill();
//     ctx.closePath();

//     setTimeout( draw, interval );
// }

// draw();


/* 1フレームごとに描画する位置を変更 */
// var interval = Math.floor(1000/60);
// var x = 5;
// var y = 5;

// function draw() {
//     x += 5;
//     y += 5;
    
//     ctx.beginPath();
//     ctx.fillStyle = "#99ff66";
//     ctx.rect( x, y, 100, 200 );
//     ctx.fill();
//     ctx.closePath();

//     setTimeout( draw, interval );
// }

// draw();


// var interval = Math.floor(1000/60);
// var x = 5;
// var y = 5;

// draw();

// function draw() {
//     ctx.clearRect(0, 0, 500, 500);

//     x += 5;
//     y += 5;
    
//     ctx.beginPath();
//     ctx.fillStyle = "#99ff66";
//     ctx.rect( x, y, 100, 200 );
//     ctx.fill();
//     ctx.closePath();

//     setTimeout( draw, interval );
// }


/* requestAnimationFrameメソッドで描画タイミングを最適化する */

//ブラウザの更新タイミングで実行
window.requestAnimationFrame =
    window.requestAnimationFrame ||
    window.mozRequestAnimationFrame ||
    window.webkitRequestAnimationFrame ||
    window.msRequestAnimationFrame ||
    function(cb) {setTimeout(cb, 17);};

var x = 5;
var y = 5;

draw();

function draw() {
    ctx.clearRect(0, 0, 500, 500);

    x += 5;
    y += 5;
    
    ctx.beginPath();
    ctx.fillStyle = "#99ff66";
    ctx.rect( x, y, 100, 200 );
    ctx.fill();
    ctx.closePath();

    requestAnimationFrame( draw );
}