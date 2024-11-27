#include "Assistance.h"	// ʵ�ó��������
#include "Polynomial.h"	// ����ʽ��
int main()
{
	char c = '1';
    Polynomial fa, fb, fc;
    PolyItem it;
    while (c != '0'){
		bool astatus = fa.IsZero(),bstatus=fb.IsZero();
        cout  <<"1. �������ʽ." << endl;
        cout  <<"2. ��ʾ����ʽ." << endl;
        cout  <<"3. ����ʽ�ӷ�." << endl;
		cout  <<"4. ����ʽ��." << endl;
		cout  <<"5. ����ʽ�˷�." << endl;
		cout << "6. ����ʽ����." << endl;
		cout << "7. ����ʽ��ֵ." << endl;
		cout << "8. �ۺ�����." << endl;
		cout << "0. �˳�." << endl;
		cout  <<"ѡ����(0~8):" << endl;
		cin >> c;
		switch (c) {
		case '1':
			// ����fa
			fa.SetZero();		// ��fa����Ϊ0
			cout << endl << "����fa����(coef, expn)(e <0 ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn >=0) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			// ����fb
			fb.SetZero();		// ��fb����Ϊ0
			cout << endl << "����fb����(coef, expn)(e <0 ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn >=0) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			break;
		case '2':
			if (astatus && bstatus) {
				puts("������fa����fb!");
				break;
			}
			if (!astatus) {
				cout << "fa:" << endl;
				fa.Display();
				cout << endl;
			}
			if (!bstatus) {
				cout << "fb:" << endl;
				fb.Display();
				cout << endl;
			}
			break;
		case '3':
			if (astatus || bstatus) {
				puts("������fa��fb!");
				break;
			}
			fc = fa + fb;
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "fa + fb:" << endl;		// ��ʾfc = fa + fb
			fc.Display();
			cout << endl;
			break;
		case '4':
			if (astatus || bstatus) {
				puts("������fa��fb!");
				break;
			}
			fc = fa.d();
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;
			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "d(fa):" << endl;			// ��ʾd(fa)
			fc.Display();
			cout << endl;
			fc = fb.d();
			cout << "d(fb)" << endl;		//��ʾd(fb)
			fc.Display();
			cout << endl;
			break;
		case '5':
			if (astatus || bstatus) {
				puts("������fa��fb!");
				break;
			}
			fc = fa * fb;
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "fa * fb:" << endl;		// ��ʾfc = fa * fb
			fc.Display();
			cout << endl;
			break;
		case '6':
			if (astatus || bstatus) {
				puts("������fa��fb!");
				break;
			}
			fc = fa - fb;
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "fa - fb:" << endl;		// ��ʾfc = fa - fb
			fc.Display();
			cout << endl;
			break;
		case '7':
			if (astatus || bstatus) {
				puts("������fa��fb!");
				break;
			}
			cout << endl << "����Ҫ����Ķ���ʽ��xֵ: ";
			int x;
			cin >> x;
			cout << "����ʽa��x = " << x << "����ֵΪ: " << fa.Evaluate(x) << endl;
			cout << "����ʽb��x = " << x << "����ֵΪ: " << fb.Evaluate(x) << endl;
			cout << "����ʽc��x = " << x << "����ֵΪ: " << fc.Evaluate(x) << endl;
			break;
		case '8':
			if (astatus || bstatus) {
				puts("������fa��fb!");
				break;
			}
			fc = fa + fb + fa.d() + fb.d();
			cout << "fa+fb+d(fa)+d(fb):" << endl;			// ��ʾfa
			fc.Display();
			cout << endl;
			break;
		default:
			break;
		}
	}
	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
}
/*
2 0
3 1
2 2
3 -1

1 0
2 1
3 2
4 -1
*/
