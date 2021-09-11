/* 複数のパーティカルを動かす */


window.requestAnimationFrame =
  window.requestAnimationFrame ||
  window.mozRequestAnimationFrame ||
  window.webkitRequestAnimationFrame ||
  window.msRequestAnimationFrame ||
  function(cb) {setTimeout(cb, 17);};

// var x = 5;
// var y = 5;

// // 1. 図形を描画（描画サイクルの開始）
// render();

// function render() {
//     // 2. 一度図形を消去
//     ctx.clearRect(0, 0, 500, 500);

//     updatePosition();
//     draw(x, y);

//     // 5. 一定時間を置く
//     requestAnimationFrame( render );
// }

// function updatePosition() {
//     // 3. 位置をずらす
//     x += 5;
//     y += 5;
// }

// function draw(posx, posy) {
//     // 4. 再度図形を描画する
//     ctx.beginPath();
//     ctx.fillStyle = "#99ff66";
//     ctx.rect( posx, posy, 100, 200 );
//     ctx.fill();
//     ctx.closePath();
// }


/* 図形の数を増やす */

// var x1 = 5;
// var y1 = 5;
// var x2 = 100;
// var y2 = 5;

// // 1. 図形を描画（描画サイクルの開始）
// render();

// function render() {
//     // 2. 一度図形を消去
//     ctx.clearRect(0, 0, 500, 500);

//     updatePosition();
//     draw(x1, y1);
//     draw(x2, y2);

//     // 5. 一定時間を置く
//     requestAnimationFrame( render );
// }

// function updatePosition() {
//     // 3. 位置をずらす
//     x1 += 5;
//     y1 += 5;
//     x2 += 5;
//     y2 += 5;
// }

// function draw(posx, posy) {
//     // 4. 再度図形を描画する
//     ctx.beginPath();
//     ctx.fillStyle = "#99ff66";
//     ctx.rect( posx, posy, 10, 20 );
//     ctx.fill();
//     ctx.closePath();
// }

/* たくさんのパーティカルを動かす */
var canvas = document.getElementById( "canvas" );
var ctx = canvas.getContext( "2d" );
var NUM = 20;
var particles = [];


canvas.width = canvas.height = 500

for(var i = 0; i < NUM; i++) {
    positionX =  Math.random()*120; // X座標を0-20の間でランダムに
    positionY =  Math.random()*20; // Y座標を0-20の間でランダムに
    particle = new Particle(ctx, positionX, positionY);
    particles.push( particle );
  }

function Particle(ctx, x, y) {
  this.ctx = ctx;
  this.x = x || 0;
  this.y = y || 0;
}

Particle.prototype.render = function(){
    this.updatePosition();
    this.draw();
}

//draw関数をParticle関数のプロトタイプに追加
Particle.prototype.draw = function() {
    // 4. 再度図形を描画する
    ctx = this.ctx;
    ctx.beginPath();
    ctx.fillStyle = "#99ff66";
    ctx.rect( this.x, this.y, 4, 20 );
    ctx.fill();
    ctx.closePath();
}

//updatePosition関数をParticle関数のプロトタイプに追加
Particle.prototype.updatePosition = function() {
    // 3. 位置をずらす
    this.x += 5;
    this.y += 5;
}

// 1. 図形を描画する
render();

function render() {
    // 2.一度図形を消去
    ctx.clearRect(0, 0, 500, 500);

    //配列の各要素の関数renderを実行して図形を描画
    particles.forEach(function(e) { e.render(); });

    //5. 一定時間を置く
    requestAnimationFrame( render );
}
