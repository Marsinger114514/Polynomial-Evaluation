#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "LinkList.h"			// ������
#include "PolyItem.h"			// ����ʽ����


// ����ʽ��
class Polynomial
{
protected:
// ����ʽʵ�ֵ����ݳ�Ա:
	LinkList<PolyItem> polyList;// ����ʽ��ɵ����Ա�

public:
	//  �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	Polynomial(){};				// �޲ι��캯��
	~Polynomial(){};			// ��������
	int Length() const;			// �����ʽ������			 
	bool IsZero() const;		// �ж϶���ʽ�Ƿ�Ϊ0
	void SetZero();				// ������ʽ��Ϊ0
	void Display();				// ��ʾ����ʽ
	void CombineLikeTerms();		// �ϲ�ͬ����
	void InsItem( const PolyItem &item);		// ����һ��
	Polynomial operator +(const Polynomial &p) const; // �ӷ����������
	Polynomial operator -(const Polynomial& p) const; // �������������
	double Evaluate(double x); //��ֵ����
	Polynomial(const Polynomial &copy);			// ���ƹ��캯��
	Polynomial(const LinkList<PolyItem> &copyLinkList);				
		// �ɶ���ʽ��ɵ����Ա������ʽ
	Polynomial d() const;						//�󵼺���
	Polynomial operator* (const Polynomial& p)const;
	Polynomial &operator =(const Polynomial &copy);	// ��ֵ�������
	Polynomial &operator =(const LinkList<PolyItem> &copyLinkList);	// ��ֵ�������
};


// ����ʽ���ʵ�ֲ���

int Polynomial::Length() const
// ������������ض���ʽ������
{
	return polyList.GetLength();
}

bool Polynomial::IsZero() const
// ��������������ʽΪ0���򷵻�true�����򷵻�false
{
	return polyList.IsEmpty();
}

void Polynomial::SetZero()
// ���������������ʽ��Ϊ0
{
	polyList.Clear(); 
}

void Polynomial::Display()
// �����������ʾ����ʽ
{
	// �Ⱥϲ�ͬ����
	CombineLikeTerms();
	// ������ʽ�Ƿ�Ϊ��
	if (polyList.IsEmpty()) {
		cout << "0" << endl; // ��������ʽ
		return;
	}
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while ( status == ENTRY_FOUND)	{// ������ʾ����ʽ��ÿһ��
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
		status = polyList.GetElem(++pos, it);	// ȡ����һ��
	}
}

void Polynomial::InsItem( const PolyItem &item)
// ��������������ʽ����һ��
{
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while ( status == ENTRY_FOUND && it.expn > item.expn) 	// ���Ҳ���λ��
			status = polyList.GetElem(++pos, it);
	polyList.InsertElem(pos, item);					            // �����ʽ����һ��
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
	Polynomial fa;							// �Ͷ���ʽ
	fa.polyList = lb;
	return fa;
}

void Polynomial::CombineLikeTerms()
// ����������ϲ�����ʽ�е�ͬ����
{
	// ����һ���µ��������ڴ�źϲ���Ľ��
	LinkList<PolyItem> combinedList;
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);

	while (status == ENTRY_FOUND) {
		// ������combinedList���ҵ���ָͬ������
		int combPos = 1;
		PolyItem combItem;
		Status combStatus = combinedList.GetElem(combPos, combItem);

		while (combStatus == ENTRY_FOUND && combItem.expn != it.expn) {
			combPos++;
			combStatus = combinedList.GetElem(combPos, combItem);
		}

		if (combStatus == ENTRY_FOUND) {
			// �ҵ�����ָͬ������ϲ�����
			combItem.coef += it.coef;
			if (combItem.coef != 0) {
				combinedList.SetElem(combPos, combItem); // ���ºϲ������
			}
			else {
				combinedList.DeleteElem(combPos, combItem); // ���ϵ��Ϊ0��ɾ������
			}
		}
		else {
			// û���ҵ���ָͬ�����ֱ����ӵ�combinedList
			combinedList.InsertElem(combPos, it);
		}

		pos++;
		status = polyList.GetElem(pos, it);
	}

	// �úϲ���������滻ԭ���Ķ���ʽ����
	polyList = combinedList;
}

inline Polynomial Polynomial::operator*(const Polynomial& p) const
{
	Polynomial temp;
	Status astatus, bstatus;
	LinkList<PolyItem>la = polyList;	//��ǰ����ʽ��Ӧ�����Ա�
	LinkList<PolyItem>lb = p.polyList;	//����ʽp��Ӧ�����Ա�
	LinkList<PolyItem>lc;				//�˶���ʽ��Ӧ�����Ա�
	PolyItem aItem, bItem;
	int aPos = 1, bPos = 1; 
	astatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1�� 
	while (astatus == ENTRY_FOUND) {
		bPos = 1;
		bstatus = lb.GetElem(bPos++, bItem);			// ȡ��lb�ĵ�1��
		while (bstatus == ENTRY_FOUND) {
			temp.InsItem(PolyItem(aItem.coef*bItem.coef,aItem.expn+bItem.expn));
			bstatus = lb.GetElem(bPos++, bItem);		//ȡ��lb����һ��
		}
		astatus = la.GetElem(aPos++, aItem);	//ȡ��la����һ��
	}
	return temp;
}

Polynomial Polynomial::operator +(const Polynomial &p) const
// ������������ص�ǰ����ʽ��p֮�͡����ӷ����������
{
	LinkList<PolyItem> la = polyList;			// ��ǰ����ʽ��Ӧ�����Ա�
	LinkList<PolyItem> lb = p.polyList;			// ����ʽp��Ӧ�����Ա�
	LinkList<PolyItem> lc;						// �Ͷ���ʽ��Ӧ�����Ա�
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	Status aStatus, bStatus;
	
	aStatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1�� 
	bStatus = lb.GetElem(bPos++, bItem);			// ȡ��lb�ĵ�1��

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND )	{
		if (aItem.expn > bItem.expn) {		// la�е���aItemָ����С
			lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ı�β 
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
		}
		else if (aItem.expn < bItem.expn) {	// lb�е���bItemָ����С
			lc.InsertElem(bItem);	// ��bItem׷�ӵ�lc�ı�β
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
		else {	// la�е���aItem��lb�е���bItemָ�����
			PolyItem sumItem(aItem.coef + bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// ������ĺ�׷�ӵ�lc�ı�β
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
	}

	while (aStatus == ENTRY_FOUND) {	// ��la��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ĺ���
		aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
	}

	while (bStatus == ENTRY_FOUND) {	// ��lb��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(bItem);	// ��bItem׷�ӵ�lc�ĺ���
		bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
	}

	Polynomial fc;							// �Ͷ���ʽ
	fc.polyList = lc;

	return fc;
}

Polynomial Polynomial::operator -(const Polynomial& p) const
// ������������ص�ǰ����ʽ��p֮�͡����������������
{
	LinkList<PolyItem> la = polyList;			// ��ǰ����ʽ��Ӧ�����Ա�
	LinkList<PolyItem> lb = p.polyList;			// ����ʽp��Ӧ�����Ա�
	LinkList<PolyItem> lc;						// �Ͷ���ʽ��Ӧ�����Ա�
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	Status aStatus, bStatus;

	aStatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1�� 
	bStatus = lb.GetElem(bPos++, bItem);			// ȡ��lb�ĵ�1��

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND) {
		if (aItem.expn > bItem.expn) {		// la�е���aItemָ����С
			lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ı�β 
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
		}
		else if (aItem.expn < bItem.expn) {	// lb�е���bItemָ����С
			lc.InsertElem(PolyItem(-bItem.coef, bItem.expn)); // ��-bItem׷�ӵ�lc�ı�β
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
		else {	// la�е���aItem��lb�е���bItemָ�����
			PolyItem sumItem(aItem.coef - bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// ������ĺ�׷�ӵ�lc�ı�β
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
	}

	while (aStatus == ENTRY_FOUND) {	// ��la��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ĺ���
		aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
	}

	while (bStatus == ENTRY_FOUND) {	// ��lb��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(PolyItem(-bItem.coef, bItem.expn)); // ��-bItem׷�ӵ�lc�ĺ���
		bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
	}

	if (lc.IsEmpty()) {
		// ����һ����ʾ�����ʽ�Ķ���
		return Polynomial(); // Ĭ�Ϲ��캯��Ӧ�ô���һ�������ʽ
	}


	Polynomial fc;							// �����ʽ
	fc.polyList = lc;

	return fc;
}

double Polynomial::Evaluate(double x) {
	double result = 0.0; // �洢����ʽ��ֵ
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);

	while (status == ENTRY_FOUND) {
		// ����ÿһ���ֵ���ۼӵ������
		result += it.coef * std::pow(x, it.expn);
		pos++;
		status = polyList.GetElem(pos, it);
	}

	return result;
}

Polynomial::Polynomial(const Polynomial &copy)
// ����������ɶ���ʽcopy�����¶���ʽ�������ƹ��캯��
{
	polyList = copy.polyList;
}

Polynomial::Polynomial(const LinkList<PolyItem> &copyLinkList)	
// ����������ɶ���ʽ��ɵ����Ա������ʽ����ת�����캯��
{
	polyList = copyLinkList;
}

Polynomial &Polynomial::operator =(const Polynomial &copy)	
// ���������������ʽcopy��ֵ����ǰ����ʽ������ֵ�������
{
	if ( &copy != this)	{
		polyList = copy.polyList;
	}
	return *this;
}

Polynomial &Polynomial::operator =(const LinkList<PolyItem> &copyLinkList)
// ���������������ʽ��ɵ����Ա�copyLinkList��ֵ����ǰ����ʽ
//	������ֵ�������
{
	polyList = copyLinkList;
	return *this;
}

#endif
