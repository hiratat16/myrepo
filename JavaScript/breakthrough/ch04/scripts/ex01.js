/* データを取得する
  非同期通信（Ajax）を行う上で役立つ「Promise/Deferred」
*/

function App(url) {
  var self = this;
  //[$.ajax]を返却するので,結果として[deferred object]を受け取る
  //thenメソッドを呼び出して処理
  this.fetch(url).then(function(data) {
    self.data = data;
  }, function(e) {
    console.error("データの取得に失敗しました");
  });
}

App.prototype.fetch = function(url) {
  return $.ajax({
    url: url,
    dataType: "json"
  });
};

App.prototype.bindEvents = function() {
  //関数onChangeのthisを固定
  _.bindAll(this, "onChange");
  //select要素のchangeイベントに[this.onChage]を登録
  $("select").on("change", this.onChange);
}

App.prototype.onChange = function(e) {
  var self = this;
  //[$("select")]から新たなfunctionの配列を作成
  var where = $("select").map(function(i, el) {
    var $el = $(el);
    return function(list) {
      //[this.sort]と[this.filter]に引数を渡して実行
      return self[$el.attr("name")](list, $el.val());
    };
  });
  //[current(Function)]の引数に[prev(Array)]を渡して実行
  var list = _.reduce(where, function(prev, current) {
    return current(prev);
  }, this.data.list);
};

App.prototype.sort = function(list, key) {
  //sortメソッドとfilterメソッド：valueが空文字列であればlistをreturnする
  if (this.isEmpty(key)) {
    return list;
  }
  //sortメソッド:listをkeyの値でソートした結果をreturnする
  return _.sortBy(list, function(e) {
    return e[key];
  });
};

App.prototype.filter = function(list, value) {
  if (this.isEmpty(value)) {
    return list;
  }
  return _.filter(list, function(e) {
    return e["group"] === "";
  });
};

App.prototype.isEmpty = function(value) {
  return value === "";
};

new App("data.json");
