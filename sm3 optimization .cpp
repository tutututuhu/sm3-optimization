#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

//һЩ׼��
//�����Ʊ��ش�ת��Ϊʮ�������ַ���
string BinToHex(string str) {
	string a = "";
	int temp = 0;
	int length = str.size();
	while (length % 4 != 0) {      
		str = "0" + str;//��������Ʊ��ش��ĳ���Ϊ4�ı���
	}
	for (int i = 0; i < length; i += 4) { 
		temp = (str[i] - '0') * 8 + (str[i + 1] - '0') * 4 + (str[i + 2] - '0') * 2 + (str[i + 3] - '0') * 1;
		if (temp < 10) {
			a += to_string(temp);
		}
		else {
			a += 'A' + (temp - 10);
		}
	}
	return a;
}

//ʮ�������ַ���ת��Ϊ�����Ʊ��ش�
string HexToBin(string str) {
	string a = "";
	string table[16] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };//�洢16��������Ӧ��4���ض����ƴ�
	int length = str.size();
	for (int i = 0; i < length; i++) {    
		char c = str[i];
		if (c >= 'A' && c <= 'F') {
			a += table[c - 'A' + 10];
		}
		else {
			a += table[c - '0'];
		}
	}
	return a;
}

//�����Ʊ��ش�ת��Ϊʮ��������
int BinToDec(string str) {
	int a1=0,a2=0,a3=0,a4 = 0;
	int length = str.size();
	for (int i = 0; i < length; i+=4) {   //ѭ��չ��
		a1 += (str[i] - '0') * pow(2, length - i - 1);  
		a2 += (str[i + 1] - '0') * pow(2, length - i - 2);
		a3 += (str[i + 2] - '0') * pow(2, length - i - 3);
		a4 += (str[i + 3] - '0') * pow(2, length - i - 4);
	}
	return a1+a2+a3+a4;
}

//ʮ��������ת��Ϊ�����Ʊ��ش�
string DecToBin(int str) {
	string a = "";
	while (str >= 1) {
		a = to_string(str % 2) + a;
		str = str / 2;
	}
	return a;
}

//ʮ�������ַ���ת��Ϊʮ��������
int HexToDec(string str) {
	int a = 0;
	int length = str.size();
	for (int i = 0; i < length; i++) {
		char c = str[i];
		if (c >= 'A' && c <= 'F') {
			a += (c - 'A' + 10) * pow(16, length - i - 1);
		}
		else {
			a += (c - '0') * pow(16, length - i - 1);
		}
	}
	return a;
}

//ʮ��������ת��Ϊʮ�������ַ���
string DecToHex(int str) {
	string a = "";
	int temp = 0;
	while (str >= 1) {
		temp = str % 16;
		if (temp < 10 && temp >= 0) {
			a = to_string(temp) + a;
		}
		else {
			a += ('A' + (temp - 10));
		}
		str = str / 16;
	}
	return a;
}
//�ַ������
string XOR(string str1, string str2) {
	string res1 = HexToBin(str1);
	string res2 = HexToBin(str2);
	string res = "";
	int length = res1.size();
	for (int i = 0; i < length; i++) {
		if (res1[i] == res2[i]) {
			res += "0";
		}
		else {
			res += "1";
		}
	}
	return BinToHex(res);
}
//�ַ�������
string AND(string str1, string str2) {
	string res1 = HexToBin(str1);
	string res2 = HexToBin(str2);
	string res = "";
	int length = res1.size();
	for (int i = 0; i <length; i++) {
		if (res1[i] == '1' && res2[i] == '1') {
			res += "1";
		}
		else {
			res += "0";
		}
	}
	return BinToHex(res);
}
//�ַ������
string OR(string str1, string str2) {
	string res1 = HexToBin(str1);
	string res2 = HexToBin(str2);
	string res = "";
	int length = res1.size();
	for (int i = 0; i < length; i++) {
		if (res1[i] == '0' && res2[i] == '0') {
			res += "0";
		}
		else {
			res += "1";
		}
	}
	return BinToHex(res);
}
//ȡ��
string NOT(string str) {
	string res1 = HexToBin(str);
	string res = "";
	int length = res1.size();
	for (int i = 0; i <length; i++) {
		if (res1[i] == '0') {
			res += "1";
		}
		else {
			res += "0";
		}
	}
	return BinToHex(res);
}
//���������
char bitXor(char str1, char str2) {
	return str1 == str2 ? '0' : '1';
}

//����������
char bitAnd(char str1, char str2) {
	return (str1 == '1' && str2 == '1') ? '1' : '0';
}

//ģ�����㣬mod 2^32
string ModAdd(string str1, string str2) {//����Ϊ16�����ַ���
	string res1 = HexToBin(str1);
	string res2 = HexToBin(str2);
	char temp = '0';
	string res = "";
	int length = res1.size();
	int i;
	for (i = length - 1; i >= 0; i--) {
		res = bitXor(bitXor(res1[i], res2[i]), temp) + res;
		if (bitAnd(res1[i], res2[i]) == '1') {
			temp = '1';
		}
		else {
			if (bitXor(res1[i], res2[i]) == '1') {
				temp = bitAnd('1', temp);
			}
			else {
				temp = '0';
			}
		}
	}
	return BinToHex(res);
}
//ѭ������
string LeftShift(string str, int len) {//lenΪ���Ƶ�λ��
	string res = HexToBin(str);
	res = res.substr(len) + res.substr(0, len);
	return BinToHex(res);
}

//����Tj����
string T(int j) {
	if (0 <= j && j <= 15) {
		return "79CC4519";
	}
	else {
		return "7A879D8A";
	}
}

//��������FF(X,Y,Z)
string FF(string str1, string str2, string str3, int j) {
	if (0 <= j && j <= 15) {
		return XOR(XOR(str1, str2), str3);
	}
	else {
		return OR(OR(AND(str1, str2), AND(str1, str3)), AND(str2, str3));
	}
}
//��������GG(X,Y,Z)
string GG(string str1, string str2, string str3, int j) {
	if (0 <= j && j <= 15) {
		return XOR(XOR(str1, str2), str3);
	}
	else {
		return OR(AND(str1, str2), AND(NOT(str1), str3));
	}
}

//ѹ�������е��û�����P0��X��
string P0(string str) {
	return XOR(XOR(str, LeftShift(str, 9)), LeftShift(str, 17));
}
//��Ϣ��չ�е��û�����P1��X��
string P1(string str) {
	return XOR(XOR(str, LeftShift(str, 15)), LeftShift(str, 23));
}


//��䣬�������Ϣ������512bit�ı���
string padding(string str) {
	string res = "";
	int length = str.size();
	for (int i = 0; i < length; i++) {  //��������ַ�����Ϊʮ������
		res += DecToHex((int)str[i]);
	}
	int res_length = res.size() * 4;//�����ַ����Ķ����Ƴ���

	res += "8";//��ӱ���"1",����ʮ������
	while (res.size() % 128 != 112) {  //���"0"
		res += "0";
	}
	string res_len = DecToHex(res_length);//�����Ƴ��ȶ�Ӧ��ʮ�������ַ���
	while (res_len.size() != 16) {//��res_len�ַ����ĳ���ӵ�16bit,��Ӧ�����Ʊ��ش���Ϊ64bit
		res_len = "0" + res_len;
	}
	res += res_len;//��Ӷ����Ƴ��ȶ�Ӧ��ʮ�������ַ���
	return res;
}



//��Ϣ��չ����:����Ϣ������չ��132����Ϣ��
string extension(string str) {
	string res = str;//W0-W15
	//����W16-W67
	for (int i = 16; i < 68; i++) {
		string tmp1 = res.substr((i - 16) * 8, 8);
		string tmp2 = res.substr((i - 9) * 8, 8);
		string tmp3 = res.substr((i - 3) * 8, 8);
		string tmp4 = res.substr((i - 13) * 8, 8);
		string tmp5 = res.substr((i - 6) * 8, 8);
		string a = LeftShift(tmp3, 15);
		string b = LeftShift(tmp4, 7);
		res += XOR(XOR(P1(XOR(XOR(tmp1, tmp2), a)), b), tmp5);
	}

	//����W'0-W'63
	for (int i = 0; i < 64; i++) {
		res += XOR(res.substr(i * 8, 8), res.substr((i + 4) * 8, 8));
	}
	return res;
}

//ѹ������
string compress(string str1, string str2) {
	string A = str2.substr(0, 8); //A-HΪ�ּĴ���
	string B = str2.substr(8, 8);
	string C = str2.substr(16, 8);
	string D = str2.substr(24, 8);
	string E = str2.substr(32, 8);
	string F = str2.substr(40, 8);
	string G = str2.substr(48, 8);
	string H = str2.substr(56, 8);
	string SS1 = "", SS2 = "", TT1 = "", TT2 = "";  //�м����

	for (int j = 0; j < 64; j++) {
		string tmp1 = LeftShift(A, 12), tmp2 = LeftShift(T(j), j % 32);
		SS1 = LeftShift(ModAdd(ModAdd(tmp1, E), tmp2), 7);
		SS2 = XOR(SS1, tmp1);
		string tmp3 = FF(A, B, C, j), tmp4 = GG(E, F, G, j);
		TT1 = ModAdd(ModAdd(ModAdd(tmp3, D), SS2), str1.substr((j + 68) * 8, 8));//TT1=FF(A,B,C)+D+SS2+W'(j)
		TT2 = ModAdd(ModAdd(ModAdd(tmp4, H), SS1), str1.substr(j * 8, 8));//TT2=GG(E,F,G)+H+SS1+W(j)
		D = C;
		C = LeftShift(B, 9);
		B = A;
		A = TT1;
		H = G;
		G = LeftShift(F, 19);
		F = E;
		E = P0(TT2);
	}
	string res = (A + B + C + D + E + F + G + H);
	return res;//����64��ѭ�����õ�ѹ��������ֵ
}

//����ѹ��
string iteration(string str) {
	int num = str.size() / 128;//����������Ϣ����ķ��飬��512bit���飬16�����¼�����128
	string V = "7380166F4914B2B9172442D7DA8A0600A96F30BC163138AAE38DEE4DB0FB0E4E";//��ʼIV,256bit
	string B = "", EXB = "", CFB = "";
	for (int i = 0; i < num; i++) {
		B = str.substr(i * 128, 128);//��i����Ϣ���飬����16����
		EXB = extension(B);
		CFB = compress(EXB, V);
		V = XOR(V, CFB);
	}
	return V;
}

//����
int main() {
	string str;
	str = "abc";
	DWORD start = GetTickCount64();
	string padding_result = padding(str);
	string res = iteration(padding_result);
	DWORD end = GetTickCount64();
	cout << "�Ӵ�ֵ��" << endl;
	for (int i = 0; i < 8; i++) {
		cout << res.substr(i * 8, 8) << " ";
	}
	cout << endl << "����ʱ��Ϊ��" << (end - start) << "ms" << endl;
}

