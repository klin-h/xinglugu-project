当前仓库的代码主要实现了土地的初始化于土地上物品的基本交互 使用方法：所有cpp 和 h文件（除了main.cpp /h）都放到class里面,mian.cpp/h 放到win32里，png放到Resource里（暂时不管用zip）。 功能： 1、初始显示土地图片，点击后改变状态，目前一共三个，可添加（图片改变）。因为后续窗口如何变化未确定，因此这里的图片没有严格匹配（可以但没必要） 2、在某一位置（给出（x，y）即可）显示某个物品，当前代码只做演示，我只添加了三棵树 3、点击物土地上物品时（如树），触发interact();该函数返回一个自定义数据类型，该数据类型里面包括本次是否点击成功，点击对象是什么，来表示这次点击的结果。 注：自定义数据类型包含的内容可以添加、修改，我这里只是写了一个框架

注：其实大家都不用看SceneObject.cpp tree.cpp等这些文件，重点看 MainScene.cpp 中 void MainScene::initTouchListener()中的注释即可。 即知道这个对外的接口能返回什么就好。这只是个大概的框架，具体内容由我后续添加，或大家告诉我需求，我来添加

usable.cpp与usable.h文件，是通过枚举的方法涵盖可使用物品（也就是可以放在背包与物品栏中的物品），这里已经实现了整体的框架与功能，具体的物品有待添加。（2024 12.4 更新） （可能包含的具体物品我已经放了，需要使用的，后续确定） 使用方法：基类Item 及其所有子类均在内部 ，实现了对其操作的基本接口，具体内容大家可自由添加 功能： 1.通过create函数，实现外部对物品的创建，这里输入对应的具体物品名，可以创建特定的物品（理论上，这是必须的）。 2.在人物手持特定物品，监视到左键或右键，触发其功能时，可以引用这里的leftKeyFunction以及rightKeyFunction来实现，功能具体内容就写在里面。 3.在要创建对象，显示特定物品的图片时，可以通过其photoOut函数获得文件名，要给物品配套文件名，在构造函数内实现。

back.cpp与back.h文件，是有关背包与物品栏功能的实现（不包含其显示，但也会提供相关接口）。（12.4 更新， 加了与钱有关的操作） 使用方法：具体需要增加的功能，声明在.h文件的类内声明，在.cpp文件内具体实现。 功能： 1.通过create函数，创建一个背包，这里我们全程应该只需要一个背包。 2.itemPositionChangeOn与itemPositionChangeOff函数，是在背包开启时，鼠标改变物品位置时使用的相应接口。 3.bottomSelect函数，是在选择物品栏物品时，返回其具体物品。 4.upgrade函数，实现对背包的升级。 5.itemAdd，在吸附物品，合成物品等功能时可以使用。 6.matchJudge,在合成物品，购买交换时，对物品进行匹配。 7.itemReduce函数，在实现相应功能之后，对物品进行削减。

WalkingCharacter.cpp和WalkingCharacter.h粗略对角色移动功能进行了实现，因为resource中基本都是走路的几个动作连在一起，所以先把图裁开再循环并移动 使用方法详见用兔子进行的测试用例，测试方法为将mainscene.cpp中init函数中的/setupWalkingCharacter(visibleSize, origin);/和setupWalkingCharacter的注释取消

2024/12/4 Author Gao wenhao ，实现了基本动物类的搭建，目前的问题，tmx地图还为完全实现，导致部分tmx文件在编译器无法打开，当前仓库里的farm_map01.tmx 是可以打开的

2024/12/4 Author Li Siyuan ,提交了exchange.cpp与exchange.h， 他们实现合成台，铁匠铺商店，Pierre商店的代码实现。 提供接口，以获得物品。

2024/12/6 Author Gao wenhao ，完善了动物类，实现了动物的随机移动（帧动画）、点击触发事件的反馈（目前log输出，提供接口） 注意拉取远仓后，记得把图片添加到resource里（目前我们的图片管理太乱了，等地图确定后统一要求）

2023/12/7 Author Gao wenhao ，当前远仓版本是最新版本主要统一解决了远仓代码的的bug、版本不统一的等等问题。

2024/12/8 Author Li Siyuan , 把usableItem文件中的常量转移至constants.h中。

2024/12/9 Author Li Siyuan ，修改了back.cpp，back.h，mainscene.cpp与mainscene.h把原先处于mainscene.cpp的背包图形化部分删除，转移到新交的文件backphoto.cpp中,主要实现了背包图形化界面的问题。

2024/12/10 Author Gao wenhao ，完善了土地交互逻辑，现在可以使用指定工具锄地/浇地/收集石头/木材等等了。注意本次resource一并更新，记得更新自己的resource文件