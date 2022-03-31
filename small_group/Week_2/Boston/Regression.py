import numpy as np

class Regression:
    #初始化对象
    #传入的是系数theta个数
    #同时使theta矩阵随机初始化
    def __init__(self,theta_num):
        self.shape=theta_num
        self.theta = np.random.rand(theta_num)

    #求值方法，即用变量乘以系数矩阵的转置
    def f(self, x):
        return np.dot(x,self.theta.T)

    #归一化方法，调用此方法可以将传入的数据归一化（这是我从网上抄的）
    def normalize(self, dataset):
        maxcol = dataset.max(axis=0)
        mincol = dataset.min(axis=0)
        data_shape = dataset.shape
        data_rows = data_shape[0]
        data_cols = data_shape[1]
        t = np.empty((data_rows, data_cols))
        for i in range(data_cols):
            t[:, i] = (dataset[:, i] - mincol[i]) / (maxcol[i] - mincol[i])
        return t

    #求均方误差方法，调用此方法，传入变量x和因变量y，可以算出其均方误差
    def mse(self, x,y):
        return np.sum((self.f(x)-y)**2)/len(y)

    #梯度下降算法方法
    def GDRegression(self, rate, nor, train_X_GD, train_y_GD):
        #rate即是算法的学习率
        #用for循环来进行循环迭代
        #nor是为了正则化，避免出现过拟合现象
        #for循环里的第一条被注释的语句是我刚开始做是从网上抄的梯度下降方法
        #未注释的是我根据师兄给定求导公式结合吴恩达的梯度下降自己写出来的
        for i in range(100000):
            #self.theta = (1-rate/nor) * self.theta - rate * np.dot(self.f(train_X_GD) - train_y_GD, train_X_GD)
            cal_1=np.dot(train_X_GD,self.theta.T)-train_y_GD
            cla_2=2*np.dot(train_X_GD.T,cal_1)
            self.theta=(1-rate/nor)*self.theta-rate*cla_2

    #最小二乘算法
    #为了不把式子写太长，我整了很多个变量来分步执行
    #其实只是把师兄给的公式加上吴恩达机器学习里的最小二乘法再加上正则化实现而已
    def OLSRegression(self,nor,X,y):
        #先点乘X的转置和X，结果赋给dot01
        dot01=np.dot(X.T,X)
        #nor01是为了正则化，但不知为何正则化后均方误差还是很大
        norm01=np.identity(self.shape)
        norm01[0,0]=0
        #求dot01正则化后矩阵的逆，其结果赋给inv01
        inv01=np.linalg.inv(dot01+(1-1/nor)*norm01)
        #再对inv01个X的转置进行点乘，结果赋给dot02
        dot02=np.dot(inv01,X.T)
        #最后再将dot02于y进行点乘，其结果即为系数矩阵
        self.theta=np.dot(dot02,y)