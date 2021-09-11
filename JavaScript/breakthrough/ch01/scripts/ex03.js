/*
//オブザーバーを理解する
//JavaScriptデザインパターンの一種
//状態の変化を監視し,あるオブジェクトの状態が変化した時,予め登録しておいた監視者に対して通知を行う

//①Observerと呼ばれるオブジェクトに監視者を登録する
//②通知者がイベントを通知する
//③監視者はイベント通知を受け取り,各々の目的を実行する

//①Observerのコンストラクタを作成
function Observer() {
    // 監視者を格納するための空の配列を作成
    this.listeners = [];
}

//②onとoffというプロトタイプを作成
//onメソッド：配列「this.listenes」に,イベントを通知したい関数を単に追加
Observer.prototype.on = function(func) {
    this.listeners.push(func);
}

//offメソッド：指定されたオブサーバーを検索し,リストから削除
Observer.prototype.off = function(func) {
    var len = this.listener.length;
    for (var i = 0; i < len; i++) {
        var listener = this.listeners[i];
        if(listener === func) {
            this.listeners.splice(i, 1);
        }
    }
};

//③tirggerというプロトタイプ関数を作成
//triggerメソッドは,オブザーバーのリスト全体を反復処理し,実行する
Observer.prototype.trigger = function(event) {
    var len = this.listeners.length;

    for(var i = 0; i < len; i++) {
        var listener = this.listeners[i];
        listener();
    }
};

var observer = new Observer();
var greet = function() {
    console.log("Good morning");
};

observer.on(greet);
observer.trigger();
*/

/*-----------------------------------------------------------------*/
//複数のイベントに対応する

//①複数のイベントに対応するため,配列ではなくオブジェクトを作成
function Observer() {
    this.listeners = {};
}

//②onメソッド
Observer.prototype.on = function(event, func) {
    // listenersに引数のeventが存在するかチェック
    if (! this.listeners[event] ) {
        //eventがなければ空の配列を作成
        this.listeners[event] = [];
    }
    //eventが存在すれば配列に追加
    this.listeners[event].push(func);
};

//③offメソッド：listeners[event]の配列を参照
Observer.prototype.off = function(event, func) {
    var ref = this.listeners[event],
    len = ref.length;
    for (var i = 0; i < len; i++) {
        var listener = ref[i];
        if (listener === func) {
            ref.splice(i, 1);
        }
    }
};

//④tirggerメソッド：listeners[event]の配列を参照
Observer.prototype.trigger = function(event) {
    var ref = this.listeners[event];
    for(var i = 0, len = ref.length; i < len; i++) {
        var listener = ref[i];
        if(typeof listener === "function") listener();
    }
;}

// 実行 //
var observer = new Observer();
var greet = function () {
    console.log("Good morning");
}
observer.on("morning", greet);
observer.trigger("morning"); // Good morning

var sayEvening = function() {
    console.log("Good evening");
};
observer.on("evening", sayEvening);
observer.trigger("evening"); //Good evening