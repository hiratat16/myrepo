/* パーティクルを装飾する */

window.requestAnimationFrame =
  window.requestAnimationFrame ||
  window.mozRequestAnimationFrame ||
  window.webkitRequestAnimationFrame ||
  window.msRequestAnimationFrame ||
  function(cb) {setTimeout(cb, 17);};

var canvas = document.getElementById( "canvas" ),
  ctx = canvas.getContext("2d"),
  NUM = 20,
  particles = [],
  W = 500,
  H = 500

canvas.width = W;
canvas.height = H;

function Particle(ctx, x, y) {
  this.ctx = ctx;
  this.initialize(x, y);
}

Particle.prototype.initialize = function(x, y) {
  this.x = x || 0;
  this.y = y || 0;
  this.radius = 50;
  // 速度用のオブジェクトv
  this.v = {
    x: Math.random()*10, //x方向の速度
    y: Math.random()*10 //y方向の速度
  };

  //描画色をランダムに設定
  this.color = {
    r: Math.floor(Math.random()*255),
    g: Math.floor(Math.random()*255),
    b: Math.floor(Math.random()*255),
    a: 1
  };
}

Particle.prototype.render = function(){
  this.updatePosition();
  this.wrapPosition();
  this.draw();
}

Particle.prototype.draw = function() {
  // 4. 描画
  ctx = this.ctx;
  ctx.beginPath();
  ctx.fillStyle = this.gradient();
  //円を描く:arcメソッド
  //arc(Z座標, Y座標, 半径, 描画角度, 描画方向:反時計回りかどうか);
  ctx.arc( this.x, this.y, this.radius, Math.PI*2, false);
  ctx.fill();
  ctx.closePath();
}

Particle.prototype.updatePosition = function() {
  // 3. 位置をずらす
  this.x += this.v.x;
  this.y += this.v.y;
}

Particle.prototype.wrapPosition = function() {
  if(this.x < 0) this.x = W;
  if(this.x > W) this.x = 0;
  if(this.y < 0) this.y = H;
  if(this.y > H) this.y = 0;
}

Particle.prototype.gradient = function() {
  //this.colorオブジェクトの値をグラデーションオブジェクtの生成に用いる
  var col = this.color.r + ", " + this.color.g + ", " + this.color.b;

  /*描画コンテキスト.createRadialGradient(x0, y0, r0, x1, y1, r1)
  x0:開始円のX座標
  y0:開始円のY座標
  r0:開始円の半径
  x1:終了円のX座標
  y2:終了円のY座標
  r1:終了円の半径 */
  var g = this.ctx.createRadialGradient( this.x, this.y, 0, this.x, this.y, 10)

  /*gradient.addColorStop(offset, color)
  offset:0~1で範囲内を指定
  color:指定箇所における色を指定*/
  //開始地点（offset:0)：不透明な黒
  g.addColorStop(0, "rgba(" + col + ", 1)")
  //開始地点（offset:0.5)：20%の透明度の黒
  g.addColorStop(0.5, "rgba(" + col + ", 0.2)")
  //終了地点（offset:1）:透明な黒
  g.addColorStop(1, "rgba(" + col + ", 0)")
  return g

}

for(var i = 0; i < NUM; i++) {
  positionX = Math.random()*W;
  positionY = Math.random()*H;
  particle = new Particle(ctx, positionX, positionY);
  particles.push( particle );
}

// 1.図形を描画
// 描画サイクルを開始する
render();

function render() {
  // 2.一度消去
  ctx.clearRect(0,0,500,500); //前回までの描画内容を消去

  particles.forEach(function(e){ e.render(); });

  // 5. 一定間隔をおく
  // requestAnimationFrameをつかって、ブラウザの更新のタイミングに実行する
  requestAnimationFrame( render );
}
