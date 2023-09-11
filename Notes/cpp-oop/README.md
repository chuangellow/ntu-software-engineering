# C++: Object-Oriented Programming

## 1. Class
Class 就是將資料和 function 包裝成一個結構的方法，不同於 C 裡頭的 struct，struct 中只能包含資料，不能包含 function。

C++ 中 class 可以用下面方式宣告：

```
class class_name {
    permission_label_1:
       member1;
    permission_label_2:
       member2;
} object_name;
```
透過宣告定義的 class，我們就能創建 object，而 class 內部的成員如資料或 function 可以給定 permission label 為：

- private：只有該 class 的其他 member 或是該 class 的 friend class 可以存取得到。
- public：任何地方都可以存取得到該 member。
- protected：除了 private 可以存取得到的成員外，還多了子類別 derived class 可以存取得到。

以下面為例：

```
class Point {
    int x, y;
    public:
        void set_values(int, int);
        int distance_to_origin(void);
} point;
```
這裡定義了一個 class 為 Point，並宣告了該 class 的物件 point，這個 class 中共有 4 個 members，分別是：

- private: x, y
- public: set_values(), distance_to_origin() 的 prototype

可以注意到，如果沒有特別定義該 class 成員的 permission label 時，會被預設為 private。

因為 set_values 和 distance 皆為 public function，我們可以在外部存取：

```
point.set_value(3, 4);
distance = point.distance_to_origin();
```

但因為 class 中只有提供 function 的 prototype，我們可以利用 scope resolution operator ```::``` 來在 class Point 外來定義 function 內容。

下面為一完整示範：

```
#include <iostream>

class Point {
		int x, y;
	public:
		void set_values(int, int);
		int distance_to_origin(void);
		int get_x(void) {return x;}
		int get_y(void) {return y;}
} point;

void Point::set_values(int a, int b) {
	x = a;
	y = b;
}

int Point::distance_to_origin(void) {
	return x*x + y*y;
}

int main(void) {
	Point new_point;
	new_point.set_values(3, 4);
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
```

scope resolution operator ```::``` 可以給予被定義的成員適當的範圍屬性，因為 set_values() 同屬 Point 的 class 中，所以可以直接引用 private 的 x, y members。

在 class 內部直接定義完整的函數，和只定義函數的原型而把具體實現放在 class 外部的唯一區別在於，在第一種情況中，編譯器(compiler) 會自動將函數作為 inline 考慮，而在第二種情況下，函數只是一般的 class 成員函數。

利用 private 的方式可以去保護 class 中的變數不被外界修改，只能透過 class 所提供的 function 來依 class 設計者所想的對 class 內的資料進行操作。

再來，透過 class 我們能造出不同的物件為 pointA 和 pointB 等等，而每個物件都有自有的變數 x, y。

另外，在 C++ 中不同於 C 的部分是 struct 同時可以有資料和 function，因此 struct 和 class 的功能相同，唯一的差別在：**class 定義的類別所有成員的默認存取權限為 private，而 struct 定義的類
別所有成員默認存取權限為 public**。

## 2. Constructors and Destructors

通常我們在宣告 object 時，會去初始化變數和分配動態記憶體，但在上面例子中，我們沒有初始化 Point 中的 x, y 值，

因此，我們在 class 中可以包含一個 constructor 的 function，來讓宣告一個該 class 的 object 時，會自動調用該 constructor 的 function 以初始化變數和分配動態記憶體。

下面就是 constructor 的定義方法：

```
#include <iostream>

class Point {
		int x, y;
	public:
		Point (int, int);
		int distance_to_origin(void);
		int get_x(void) {return x;}
		int get_y(void) {return y;}
};

Point::Point(int a, int b) {
	x = a;
	y = b;
}

int Point::distance_to_origin(void) {
	return x*x + y*y;
}

int main(void) {
	Point new_point (3, 4);
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
```

可以看到，這邊的 ```Point::Point``` 就是 constructor function 的定義，會在宣告 Point 時初始化 x, y 值。

特別注意 constructor function 的定義不會有返回值。

而 destructor 則是和 constructor 相反的功能，他會在 object 被記憶體釋放時自動調用，destructor 主要用於當我們希望物件存在的 scope 結束時，我們希望釋放該 object 使用的空間時。

下面為一使用 destructor 的例子：

```
#include <iostream>

class Point {
		int *x, *y;
	public:
		Point (int, int);
		~Point ();
		int distance_to_origin(void);
		int get_x(void) {return *x;}
		int get_y(void) {return *y;}
};

Point::Point(int a, int b) {
	x = new int;
	y = new int;
	*x = a;
	*y = b;
}

Point::~Point() {
	delete x;
	delete y;
}

int Point::distance_to_origin(void) {
	return (*x)*(*x) + (*y)*(*y);
}

int main(void) {
	Point new_point (3, 4);
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
```