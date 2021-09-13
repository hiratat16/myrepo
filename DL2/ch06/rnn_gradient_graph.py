import numpy as np
import matplotlib as plt

N = 2 #ミニバッチサイズ
H = 3 #隠れ状態ベクトルの次元数
T = 20 #時系列データの長さ

dh = np.ones((N, H)) #初期化
np.random.seed(3) #再現性のための乱数のシードを固定
#①変更前
#Wh = np.random.randn(H, H)
#②変更後
Wh = np.random.randn(H, H) * 0.5



norm_list = []
for t in range(T): #逆伝播のMatMulノードの数だけdhを更新
    dh = np.dot(dh, Wh.T)
    #dhの大きさとしてミニバッチ（N個）における平均の「L2ノルム」を求める
    #「L2ノルム」各要素の2乗の総和に対して平方根を適用
    norm = np.sqrt(np.sum(dh**2)) / N 
    norm_list.append(norm) #各ステップでのdhの大きさを配列norm_listに追加

print(norm_list)

# グラフの描画
plt.plot(np.arange(len(norm_list)), norm_list)
plt.xticks([0, 4, 9, 14, 19], [1, 5, 10, 15, 20])
plt.xlabel('time step')
plt.ylabel('norm')
plt.show()

# 結果
# ①変更前
# 勾配爆発（exploding gradients）勾配の大きさは指数関数的に増加
# ②変更後
# 勾配喪失：勾配dhの大きさは,時間サイズに比例して指数的に減少