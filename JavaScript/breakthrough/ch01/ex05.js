function AppModel(attrs) {
    this.val = "";
    //オブザーバーの機能を追加
    //使用するvalidation patternを設定するオブジェクトを追加
    this.attrs = {
        required: "",
        maxlength: 8,
        minlength: 4
    };
    //オブザーバー機能の追加
    this.listeners = {
        valid: [],
        invalid: []
    };
}

AppModel.prototype.on = function(event, func) {
    this.listeners[event].push(func);
};

AppModel.prototype.trigger = function(event) {
    $.each(this.listeners[event], function() {
        this();
    });
}

AppModel.prototype.set = function(val) {
    //引数で受け取ったvalと「this.val」を比較し,変化がなければ,以降の処理は行わない
    if (this.val === val) return;
    //変化があれば,「this.val」に引数valを代入
    this.val = val;
    this.validate();
};

AppModel.prototype.validate = function() {
    var val;
    //バリデーションでエラーが出たものを保存しておくための空の配列を用意
    this.errors = [];

    for (var key in this.attrs) {
        val = this.attrs[key];
        //AppModelの添字にkeyを渡すことでメソッドを取り出し,valの引数を渡して実行
        if(!this[key](val)) this.errors.push(key);
    }

    //バリデーション後,「this.erros」の中身が空であればvalidイベントを通知し,
    //空でなければinvalidイベントを通知する
    this.trigger(!this.errors.length ? "valid" : "invalid");
};



//値が空かどうかを判定するrequiredメソッド
AppModel.prototype.required = function() {
    return this.val !== "";
};

//値の文字数が引数num以上かどうかを判定するmaxlengthメソッド
AppModel.prototype.maxlength = function(num) {
    return num >= this.val.length;
};

//値の文字数が引数num以下かどうかを判定するminlengthメソッド
AppModel.prototype.minlength = function(num) {
    return num <= this.val.length;
};


function AppView(el) {
    this.initialize(el);
    //インスタンス化したときに,handleEventsメソッドを実行するようにする
    this.handleEvents();
}

AppView.prototype.initialize = function(el) {
    this.$el = $(el);

    //[this.$el]の隣のliを[this.$list]に代入
    this.$list = this.$el.next().children();

    //「this.$el」のdata属性を変数objに代入し,required属性があればobjに「{required:''}」をマージする
    var obj = this.$el.data();

    //propメソッド:jQueryで使用可能なメソッドのこと,主にチェックボタンやラジオボタンの選択値を取得するために使用
    if (this.$el.prop("required")) {
        obj["required"] = "";
    }

    //先ほど作ったAppModelにobjを渡してインスタンス化したものを「this.model」に代入
    //→「this.model」を通してmodelメソッドを使用できる
    this.model = new AppModel(obj);
};

AppView.prototype.handleEvents = function() {
    var self = this;

    //handleEventsメソッド:keyupイベントのイベントハンドラにonKeyupを登録
    this.$el.on("keyup", function(e) {
        self.onKeyup(e);
    });

    //modelのonメソッドを使用して,model event(valid・invalidイベント)にイベントハンドラを登録
    this.model.on("valid", function() {
        self.onValid();
    });

    this.model.on("invalid", function() {
        self.onInvalid();
    });
};

AppView.prototype.onKeyup = function(e) {
    var $target = $(e.currentTarget);

    //[this.model]のsetメソッドを使用して,inputの値をmodelにセットする
    this.model.set($target.val());
};

//[this.$el]の[class="error"]を消し,[this.$list]を非表示にする
AppView.prototype.onValid = function() {
    this.$el.removeClass("error");
    this.$list.hide();
};

//[this.$el]に[class="error"]を付与し,[this.$list]の中で該当エラーのみ表示
AppView.prototype.onInvalid = function() {
    var self = this;
    this.$el.addClass("error");
    this.$list.hide();

    $.each(this.model.errors, function(index, val) {
        self.$list.filter("[data-error=\"" + val + "\"]").show();
    });
};

$("input").each(function() {
    new AppView(this);
});