#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "LinkList.h"			// 链表类
#include "PolyItem.h"			// 多项式项类


// 多项式类
class Polynomial
{
protected:
// 多项式实现的数据成员:
	LinkList<PolyItem> polyList;// 多项式组成的线性表

public:
	//  抽象数据类型方法声明及重载编译系统默认方法声明:
	Polynomial(){};				// 无参构造函数
	~Polynomial(){};			// 析构函数
	int Length() const;			// 求多项式的项数			 
	bool IsZero() const;		// 判断多项式是否为0
	void SetZero();				// 将多项式置为0
	void Display();				// 显示多项式
	void CombineLikeTerms();		// 合并同类项
	void InsItem( const PolyItem &item);		// 插入一项
	Polynomial operator +(const Polynomial &p) const; // 加法运算符重载
	Polynomial operator -(const Polynomial& p) const; // 减法运算符重载
	double Evaluate(double x); //求值函数
	Polynomial(const Polynomial &copy);			// 复制构造函数
	Polynomial(const LinkList<PolyItem> &copyLinkList);				
		// 由多项式组成的线性表构造多项式
	Polynomial d() const;						//求导函数
	Polynomial operator* (const Polynomial& p)const;
	Polynomial &operator =(const Polynomial &copy);	// 赋值语句重载
	Polynomial &operator =(const LinkList<PolyItem> &copyLinkList);	// 赋值语句重载
};


// 多项式类的实现部分

int Polynomial::Length() const
// 操作结果：返回多项式的项数
{
	return polyList.GetLength();
}

bool Polynomial::IsZero() const
// 操作结果：如多项式为0，则返回true，否则返回false
{
	return polyList.IsEmpty();
}

void Polynomial::SetZero()
// 操作结果：将多项式置为0
{
	polyList.Clear(); 
}

void Polynomial::Display()
// 操作结果：显示多项式
{
	// 先合并同类项
	CombineLikeTerms();
	// 检查多项式是否为空
	if (polyList.IsEmpty()) {
		cout << "0" << endl; // 输出零多项式
		return;
	}
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while ( status == ENTRY_FOUND)	{// 依次显示多项式的每一项
	    if (pos > 1 && it.coef>0)
          cout<<"+";
		if (it.coef != 1)
			if (it.coef != -1)
				cout << it.coef;
			else if (it.expn != 0)
				cout << "-";
			else
				cout << it.coef;
		else if (it.coef == 1) {
			if (it.expn < 1) {
				cout << it.coef;
			}
		}
        if (it.expn > 1)
           cout << "x^" << it.expn ; 
        else
           if (it.expn == 1)
               cout << "x"  ;
		status = polyList.GetElem(++pos, it);	// 取出下一项
	}
}

void Polynomial::InsItem( const PolyItem &item)
// 操作结果：向多项式插入一项
{
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while ( status == ENTRY_FOUND && it.expn > item.expn) 	// 查找插入位置
			status = polyList.GetElem(++pos, it);
	polyList.InsertElem(pos, item);					            // 向多项式插入一项
}

Polynomial Polynomial::d() const {
	LinkList<PolyItem> la = polyList;
	LinkList<PolyItem> lb;
	int aPos = 1;
	PolyItem aItem;
	Status aStatus;
	aStatus = la.GetElem(aPos++, aItem);

	while (aStatus == ENTRY_FOUND) {
		aItem.coef = aItem.coef * aItem.expn;
		aItem.expn--;
		if(aItem.expn!=-1)
			lb.InsertElem(aItem);
		aStatus = la.GetElem(aPos++, aItem);
	}
	Polynomial fa;							// 和多项式
	fa.polyList = lb;
	return fa;
}

void Polynomial::CombineLikeTerms()
// 操作结果：合并多项式中的同类项
{
	// 创建一个新的链表用于存放合并后的结果
	LinkList<PolyItem> combinedList;
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);

	while (status == ENTRY_FOUND) {
		// 尝试在combinedList中找到相同指数的项
		int combPos = 1;
		PolyItem combItem;
		Status combStatus = combinedList.GetElem(combPos, combItem);

		while (combStatus == ENTRY_FOUND && combItem.expn != it.expn) {
			combPos++;
			combStatus = combinedList.GetElem(combPos, combItem);
		}

		if (combStatus == ENTRY_FOUND) {
			// 找到了相同指数的项，合并它们
			combItem.coef += it.coef;
			if (combItem.coef != 0) {
				combinedList.SetElem(combPos, combItem); // 更新合并后的项
			}
			else {
				combinedList.DeleteElem(combPos, combItem); // 如果系数为0，删除该项
			}
		}
		else {
			// 没有找到相同指数的项，直接添加到combinedList
			combinedList.InsertElem(combPos, it);
		}

		pos++;
		status = polyList.GetElem(pos, it);
	}

	// 用合并后的链表替换原来的多项式链表
	polyList = combinedList;
}

inline Polynomial Polynomial::operator*(const Polynomial& p) const
{
	Polynomial temp;
	Status astatus, bstatus;
	LinkList<PolyItem>la = polyList;	//当前多项式对应的线性表
	LinkList<PolyItem>lb = p.polyList;	//多项式p对应的线性表
	LinkList<PolyItem>lc;				//乘多项式对应的线性表
	PolyItem aItem, bItem;
	int aPos = 1, bPos = 1; 
	astatus = la.GetElem(aPos++, aItem);			// 取出la的第1项 
	while (astatus == ENTRY_FOUND) {
		bPos = 1;
		bstatus = lb.GetElem(bPos++, bItem);			// 取出lb的第1项
		while (bstatus == ENTRY_FOUND) {
			temp.InsItem(PolyItem(aItem.coef*bItem.coef,aItem.expn+bItem.expn));
			bstatus = lb.GetElem(bPos++, bItem);		//取出lb的下一项
		}
		astatus = la.GetElem(aPos++, aItem);	//取出la的下一项
	}
	return temp;
}

Polynomial Polynomial::operator +(const Polynomial &p) const
// 操作结果：返回当前多项式与p之和——加法运算符重载
{
	LinkList<PolyItem> la = polyList;			// 当前多项式对应的线性表
	LinkList<PolyItem> lb = p.polyList;			// 多项式p对应的线性表
	LinkList<PolyItem> lc;						// 和多项式对应的线性表
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	Status aStatus, bStatus;
	
	aStatus = la.GetElem(aPos++, aItem);			// 取出la的第1项 
	bStatus = lb.GetElem(bPos++, bItem);			// 取出lb的第1项

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND )	{
		if (aItem.expn > bItem.expn) {		// la中的项aItem指数较小
			lc.InsertElem(aItem);	// 将aItem追加到lc的表尾 
			aStatus = la.GetElem(aPos++, aItem);// 取出la的第下一项
		}
		else if (aItem.expn < bItem.expn) {	// lb中的项bItem指数较小
			lc.InsertElem(bItem);	// 将bItem追加到lc的表尾
			bStatus = lb.GetElem(bPos++, bItem);// 取出lb的第下一项
		}
		else {	// la中的项aItem和lb中的项bItem指数相等
			PolyItem sumItem(aItem.coef + bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// 将两项的和追加到lc的表尾
			aStatus = la.GetElem(aPos++, aItem);// 取出la的第下一项
			bStatus = lb.GetElem(bPos++, bItem);// 取出lb的第下一项
		}
	}

	while (aStatus == ENTRY_FOUND) {	// 将la的剩余项追加到lc的后面
		lc.InsertElem(aItem);	// 将aItem追加到lc的后面
		aStatus = la.GetElem(aPos++, aItem);// 取出la的第下一项
	}

	while (bStatus == ENTRY_FOUND) {	// 将lb的剩余项追加到lc的后面
		lc.InsertElem(bItem);	// 将bItem追加到lc的后面
		bStatus = lb.GetElem(bPos++, bItem);// 取出lb的第下一项
	}

	Polynomial fc;							// 和多项式
	fc.polyList = lc;

	return fc;
}

Polynomial Polynomial::operator -(const Polynomial& p) const
// 操作结果：返回当前多项式与p之和——减法运算符重载
{
	LinkList<PolyItem> la = polyList;			// 当前多项式对应的线性表
	LinkList<PolyItem> lb = p.polyList;			// 多项式p对应的线性表
	LinkList<PolyItem> lc;						// 和多项式对应的线性表
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	Status aStatus, bStatus;

	aStatus = la.GetElem(aPos++, aItem);			// 取出la的第1项 
	bStatus = lb.GetElem(bPos++, bItem);			// 取出lb的第1项

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND) {
		if (aItem.expn > bItem.expn) {		// la中的项aItem指数较小
			lc.InsertElem(aItem);	// 将aItem追加到lc的表尾 
			aStatus = la.GetElem(aPos++, aItem);// 取出la的第下一项
		}
		else if (aItem.expn < bItem.expn) {	// lb中的项bItem指数较小
			lc.InsertElem(PolyItem(-bItem.coef, bItem.expn)); // 将-bItem追加到lc的表尾
			bStatus = lb.GetElem(bPos++, bItem);// 取出lb的第下一项
		}
		else {	// la中的项aItem和lb中的项bItem指数相等
			PolyItem sumItem(aItem.coef - bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// 将两项的和追加到lc的表尾
			aStatus = la.GetElem(aPos++, aItem);// 取出la的第下一项
			bStatus = lb.GetElem(bPos++, bItem);// 取出lb的第下一项
		}
	}

	while (aStatus == ENTRY_FOUND) {	// 将la的剩余项追加到lc的后面
		lc.InsertElem(aItem);	// 将aItem追加到lc的后面
		aStatus = la.GetElem(aPos++, aItem);// 取出la的第下一项
	}

	while (bStatus == ENTRY_FOUND) {	// 将lb的剩余项追加到lc的后面
		lc.InsertElem(PolyItem(-bItem.coef, bItem.expn)); // 将-bItem追加到lc的后面
		bStatus = lb.GetElem(bPos++, bItem);// 取出lb的第下一项
	}

	if (lc.IsEmpty()) {
		// 返回一个表示零多项式的对象
		return Polynomial(); // 默认构造函数应该创建一个零多项式
	}


	Polynomial fc;							// 差多项式
	fc.polyList = lc;

	return fc;
}

double Polynomial::Evaluate(double x) {
	double result = 0.0; // 存储多项式的值
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);

	while (status == ENTRY_FOUND) {
		// 计算每一项的值并累加到结果中
		result += it.coef * std::pow(x, it.expn);
		pos++;
		status = polyList.GetElem(pos, it);
	}

	return result;
}

Polynomial::Polynomial(const Polynomial &copy)
// 操作结果：由多项式copy构造新多项式——复制构造函数
{
	polyList = copy.polyList;
}

Polynomial::Polynomial(const LinkList<PolyItem> &copyLinkList)	
// 操作结果：由多项式组成的线性表构造多项式——转换构造函数
{
	polyList = copyLinkList;
}

Polynomial &Polynomial::operator =(const Polynomial &copy)	
// 操作结果：将多项式copy赋值给当前多项式——赋值语句重载
{
	if ( &copy != this)	{
		polyList = copy.polyList;
	}
	return *this;
}

Polynomial &Polynomial::operator =(const LinkList<PolyItem> &copyLinkList)
// 操作结果：将多项式组成的线性表copyLinkList赋值给当前多项式
//	——赋值语句重载
{
	polyList = copyLinkList;
	return *this;
}

#endif
