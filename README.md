#markdown，文本修饰符，用特殊符号修饰正文效果<br>
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题

## 正文内容
	输入正文内容，但是如果需要换行，用\<br>\标签

## 修饰正文

   *一段测试文本*

   **一段测试文本**
   ***一段测试文本***
   ~~一段测试文本~~

## 引用效用\>表示
> 你自己就是一座金矿，关键在于如何挖掘和利用自己
>> 苏格拉底
>>> 三级引用
>>>> 四级引用

## 列表修饰符
### 无序列表 \*
* 二次元游戏
  * 元神
    * 人物
* 一级
  * 二级
    * 三级
### 有序列表 1.
1. 物理学
   1. 粒子物理
   2. 原子核物理
   3. 凝聚态物理
2. 计算机科学
   1. 分布式架构
   2. 云计算
### 混合列表
1. 测试一级
   * 测试二级
   2. 测试二级

### 列表
名称|技能|排行
--|:--:|--:
蝙蝠侠|有钱|78
海王|游泳|46
闪电侠|跑步|42

### 代码片段

```c
	include<stdio.h>
	int main(){
	    printf("test code\n");
            return 0;
	}
```
## 超链接技术
[Github](https://www.baidu.com/?tn=68018901_16_pg)

##插入图片
![图片]()

# Github

## 关键字查询
* awesome：去此类标签类别中查询项目
* python tutorial：查询资料、书籍、文档
* socket sample：查询对应技术的代码样本

## Github三要素
### repository仓库
仓库是github项目管理存储基本单位。
一个仓库中存储多个项目，一个用户可以拥有多个仓库，一般一个仓库分为public, private。
### commit提交
程序员在整个开发周期，有大量的对代码资源的迭代和修改，都可以通过commit的方式进行记录，便于程序员回溯代码，即使这些代码被删除。
提交便于使用者观察整个工程的开发流程以及设计流程。
### branch分支
在仓库中可以包含多个分支，分支才是代码文件的第一存储单位，默认的仓库主分支为master或main。
不仅可以管理代码存储，还便于多人协作开发。

## 仓库内容
* code：资源存储，代码资源，二进制，项目管理脚本，许可证等
* issues：使用时遇到的bug或进行提交，等待反馈
* README：使用markdown语言编写，工程自述文件，开发进度，版本更新，使用介绍等。
* LICENSE许可证：GPL 2.0,3.0. Apahce 2.0, Mit 这些许可证，给使用者最大使用权限以及最少的限制。

## Git软件，分布式版本控制系统
仓库管理软件，使用git管理私人代码或企业代码
   本地内容（新版）---Git更新---> 发布内容（旧版）

## 设备认证
### 1.如何让网站的账户与设备绑定（后续完成代码的管理、上传下载）
* git init //创建本地仓库      *后续对仓库的操作，都要在仓库位置*
* git config --list //查看git的配置文件
* git config --global user.email "邮箱"      *SSH远程访问*
* git config --global user.name "用户名"
* ssh-keygen -t rsa -C "注册邮箱" //创建本地密文
#### 去对应的目录查找密文文件
rsa.pub复制密文，粘贴到github的settings -> SSH key and GPG -> new ssh key -> 粘贴
ssh -T git@github.com //测试关联是否成功
### 2.为仓库起别名，定位目标仓库，后续上传
* git remote add origin "ssh地址" //为ssh仓库地址创建别名为origin
* git remote remove origin //删除origin别名

## 本地设备与云端仓库的交互逻辑
* git add code.c //添加内容到git缓冲区
   * git rm //删除本地文件并删除仓库数据
   * git restore //恢复被删除（仓库存在的话）
* git commit "提交说明" //提交到本地仓库
* git push origin master //上传到云端仓库。分支名一样就覆盖，否则云端再开一个新分支

## 代码更新的依赖关系被破坏
本地内容要比云端新，完成更新替换。但是如果直接修改云端内容，就会导致无法再次提交。
先拉取git pull云端内容，与本地内容合并或操作，而后再次推即可
git pull --rebase origin master
git rebase --skip //忽略本地内容，保留云端内容
git rebase --abort //忽略云端内容，保留本地内容
git rebase --continue //版本合并

## 下载开源代码
git clone "https仓库地址" //下载开源项目code资源

## 分支Branch
关于分支的相关命令：创建分支，选择分支，合并分支等。

## Markdown语言
github可以编写readme文本修饰语言
