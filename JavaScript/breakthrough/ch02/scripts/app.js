//Modalオブジェクトのベースを作成
function Modal(el) {
    this.initialize(el);
}

Modal.prototype.initialize = function(el) {
    this.$el = el;
    this.$container = $("#modal");
    this.$contents = $("#modal-contents");

    // this.$close = $("#modal-close");
    // this.$next = $("#modal-next");
    // this.$prev = $("#modal-prev");

    this.$overlay = $("#modal-overlay");
    //[this.$el]の親要素であるul要素を定義
    this.$parents = this.$el.parents("ul");
    this.$window = $(window);

    //Modalオブジェクトをインスタンス化した時にhandleEventsメソッドを実行するようにする
    this.handleEvents();
};

Modal.prototype.handleEvents = function() {

    //handleEventsメソッド
    //$elをクリックした時に呼ばれるcallbackにshowメソッドを登録
    // this.$el.on("click", function(e) {
    //     self.show(e);
    //     return false;
    //});

    var self = this;
    //[this.$parents]に対してイベントを設定し、onメソッドの第2引数にaを追加して、delegate方式の書き方に変更する
    this.$parents.on("click", "a", function(e) {
      self.show(e);
      return false;
    });

    this.$container.on("click", "#modal-next", function(e) {
      self.next(e);
      return false;
    });
    this.$container.on("click", "#modal-prev", function(e) {
      self.prev(e);
      return false;
    });
    this.$container.on("click", "#modal-close", function(e) {
      self.hide(e);
      return false;
    });

    //[this.$close]のclickイベントのイベントハンドラに,hideメソッドを実行する関数を登録
    // this.$close.on("click", function(e) {
    //     self.hide(e);
    //     return false;
    // });

    //[this.$overlay]のclickイベントのイベントハンドラに,hideメソッドを実行する関数を登録
    this.$overlay.on("click", function(e) {
        self.hide(e);
        return false;
    });

    //[this.$next](次へボタン):clickイベントのイベントハンドラにnextメソッドを実行する関数を登録
    // this.$next.on("click", function(e) {
    //     self.next(e);
    //     return false;
    // });

    //[this.$prev](前へボタン):clickイベントのイベントハンドラにprevメソッドを実行する関数を登録
    // this.$prev.on("click", function(e) {
    //     self.prev(e);
    //     return false;
    // });

    //[this.$window]のresizeイベントのイベントハンドラにresizeメソッドを登録
    this.$window.on("load resize", function() {
      self.resize();
    });
};

/*============モーダルウィンドウを表示するためのshowメソッド===============*/
Modal.prototype.show = function(e) {
    //クリックした要素の[$target.attr('href')(モーダルウィンドウで表示したい画像へのパス)]を取得
    var $target = $(e.currentTarget),
        src = $target.attr("href");
    this.$contents.html("<img src=\"" + src + "\" />");
    this.$container.fadeIn();
    this.$overlay.fadeIn();

    //[var index]を作ることにより,このメソッドの外からアクセスできないようにする
    var index = $target.data("index");
    //countChangeメソッドをcreateCounterに変更
    //引数を2つに変更し,変数indexを引数として渡す
    this.countChange = this.createCounter(index, this.$el.length);
    return false;
};


/*============モーダルウィンドウを閉じる===============*/
//fadeOutメソッドを使って[this.$container]と[this.$overlay]をフェードアウトする
Modal.prototype.hide = function(e) {
    this.$container.fadeOut();
    this.$overlay.fadeOut();
};

//slideメソッド
//現在表示させている画像をfadeOutさせてから,引数で受け取ったインデックスの画像をfadeInさせる
Modal.prototype.slide = function(index) {
    this.$contents.find("img").fadeOut({
        complete: function() {
            var src = $("[data-index=\"" + index + "\"]").find("img").attr("src");
            $(this).attr("src", src).fadeIn();
        }
    });
};

//countChageメソッド：次に表示したい画像のインデックスを取得
// Modal.prototype.countChange = function(num, index, len) {
//     return (index + num + len) % len;
// };

//変更前：計算した値を返す
//変更後:[this.countChage]に[this.creatCouter]の返り値がセットされる
Modal.prototype.createCounter = function(index, len) {
    return function(num) {
        return index = (index + num + len) % len;
    };
};

//nextメソッドとprevメソッドでは,countChangeメソッドを使って,
//現在表示している画面のインデックスをもとに次のインデックスを計算し,その値をslideメソッドに渡す
// Modal.prototype.next = function() {
//     this.index = this.countChange( 1, this.index, this.$el.length);
//     this.slide(this.index);
// };

//this.countChageに返り値の関数がセットされたため,数値を引数に渡すだけで,次に表示したいインデックスを取得できる
Modal.prototype.next = function() {
    this.slide(this.countChange( 1 ));
}

// Modal.prototype.prev = function() {
//     this.index = this.countChange( -1, this.index, this.$el.length);
//     this.slide(this.index);
// };

Modal.prototype.prev = function() {
    this.slide(this.countChange( -1 ));
};

//resize method: ブラウザウィンドウ幅によって「this.$container」のサイズを変更させる
Modal.prototype.resize = function() {
  var w = this.$window.width();
  if(w < 640) {
    this.$container.css({"width":"320","height":"213"});
  } else {
    this.$container.css({"width":"750","height":"500"});
  }
};

var modal = new Modal($("#modal-thumb a"));

$("#more-btn").on("click", function() {
  var html = '<li><a href="images/phot-04.jpg" data-index="3"><img alt="" src="images/photo-04.jpg" width="160" class="img-thumbnail"></a></li>';
  $(html).appendTo($("modal-thumb")).hide().fadeIn();
  $(this).fadeOut();
  modal.$el = $("modal-thumb a");
});
