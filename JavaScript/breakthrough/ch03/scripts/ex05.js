/* 表現のディティール */

window.requestAnimationFrame =
  window.requestAnimationFrame ||
  window.mozRequestAnimationFrame ||
  window.webkitRequestAnimationFrame ||
  window.msRequestAnimationFrame ||
  function(cb) {setTimeout(cb, 17);};

var canvas = document.getElementById( "canvas" ),
  ctx = canvas.getContext("2d"),
  NUM = 20,
  LIFEMAX = 100,
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
  this.radius = 250;
  this.startLife = Math.ceil( LIFEMAX * Math.random() ); //寿命の初期値:LIFEMAXを上限としてランダムに設定
  this.life = this.startLife; //現在の寿命
  // 速度用のオブジェクトv
  this.v = {
    x: Math.random()*10-5, //x方向の速度
    y: Math.random()*10-5 //y方向の速度
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
  this.updateParams();
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

Particle.prototype.updateParams = function() {
  var ratio = this.life / this.startLife; //現在の寿命がどれくらい残っているか
  this.color.a = 1 - ratio; //ratioは1から0まで変化
  this.life -= 1; //1からratioを引くことで,0から1に向かってa（透明度）が変化する
  if( this.life === 0 ) this.initialize(); //lifeが0になったら、最初期化
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
  var g = this.ctx.createRadialGradient( this.x, this.y, 0, this.x, this.y, this.radius);

  /*gradient.addColorStop(offset, color)
  offset:0~1で範囲内を指定
  color:指定箇所における色を指定*/
  g.addColorStop(0, "rgba(" + col + ", " + (this.color.a * 1) + ")");
  g.addColorStop(0.5, "rgba(" + col + ", " + (this.color.a * 0.2) + ")");
  g.addColorStop(1, "rgba(" + col + ", " + (this.color.a * 0) + ")");
  return g

}

// 1.図形を描画
for(var i = 0; i < NUM; i++) {
  var positionX = Math.random()*W;
  positionY = Math.random()*H;
  particle = new Particle(ctx, positionX, positionY);
  particles.push( particle );
}

// 描画サイクルを開始する
render();

function render() {
  // 2.一度消去
  ctx.clearRect(0,0,W,H); //前回までの描画内容を消去

  //描画モードを比較的に
  ctx.globalCompositeOperation = "lighter";

  particles.forEach(function(e){ e.render(); });

  // 5. 一定間隔をおく
  // requestAnimationFrameをつかって、ブラウザの更新のタイミングに実行する
  requestAnimationFrame( render );
}
