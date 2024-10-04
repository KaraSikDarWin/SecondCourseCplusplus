#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int const PowerAlfa =256;


//void badCharHeuristic( string str, int size, int badchar[PowerAlfa])
//{
//    int i;
//    // Initializing all occurrences as -1
//    for (i = 0; i < PowerAlfa; i++)
//        badchar[i] = -1;
//
//    // Fill the actual value of last occurrence
//    // of a character
//    for (i = 0; i < size; i++)
//        badchar[(int) str[i]] = i;
//}
//
//void search( string txt, string pat)
//{
//    int m = pat.size();
//    int n = txt.size();
//    int badchar[PowerAlfa];
//
//    /* Fill the bad character array by calling
//    the preprocessing function badCharHeuristic()
//    for given pattern */
//    badCharHeuristic(pat, m, badchar);
//
//    int s = 0;
//    while(s <= (n - m))
//    {
//        int j = m - 1;
//        /* Keep reducing index j of pattern while
//	characters of pattern and text are
//	matching at this shift s */
//        while(j >= 0 && pat[j] == txt[s + j])
//            j--;
//
//        /* If the pattern is present at current
//        shift, then index j will become -1 after
//        the above loop */
//        if (j < 0)
//        {
//            cout << "pattern occurs at shift = " << s << endl;
//            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
//        }
//        else
//            s += max(1, j - badchar[txt[s + j]]);
//    }
//}
/* Driver code */




//void RabinKarpSearch(string pat, string txt)
//{
//    int M = pat.length();
//    int N = txt.length();
//    int i, j;
//    int p = 0;
//    int t = 0;
//
//    for (i = 0; i < M; i++) {
//        p = ( p + pat[i]);
//        t = ( t + txt[i]);
//    }
//
//    for (i = 0; i <= N - M; i++) {
//
//        if (p == t) {
//
//            for (j = 0; j < M; j++) {
//                if (txt[i + j] != pat[j]) {
//                    break;
//                }
//            }
//
//            if (j == M)
//                cout << "Pattern found at index " << i<< endl;
//        }
//
//        if (i < N - M) {
//            t = (t - txt[i]  + txt[i + M]) ;
//
//        }
//    }
//}
//
//int main()
//{
//    string txt= "Mazda rx 7";
//    string pat = "rx 7";
//
//
//
//    return 0;
//}




///* C program for Boyer Moore Algorithm with
//   Good Suffix heuristic to find pattern in
//   given text string */

//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//
//
//void pr(string pat, int p){
//    int m = pat.length();
//    for (int i =p; i<m; i++){
//        cout<<pat[i];
//    }
//    cout<<endl;
//}
//
//void pr1(string pat, int p){
//    int m = pat.length();
//    for (int i =0; i<p; i++){
//        cout<<pat[i];
//    }
//    cout<<endl;
//}
//
//////// preprocessing for strong good suffix rule
//void preprocess_strong_suffix(int *shift, int *bpos, string pat, int m)
//{
//    // m is the length of pattern
//    int i=m, j=m+1;
//    bpos[i]=j;
//
//    while(i>0)
//    {
//
//        cout<<"Whl"<<" "<<i<<" ";
//        pr(pat,i);
//
//
//        /*if character at position i-1 is not equivalent to
//          character at j-1, then continue searching to right
//          of the pattern for border */
//        while(j<=m && (pat[i-1] != pat[j-1]))
//        {
////            pr(pat,i);
//            /* the character preceding the occurrence of t in
//               pattern P is different than the mismatching character in P,
//               we stop skipping the occurrences and shift the pattern
//               from i to j */
//            if (shift[j]==0) {
//                shift[j] = j - i;
//                pr(pat,i);
//            }
//
//            //Update the position of next border
//            j = bpos[j];
//        }
//        /* p[i-1] matched with p[j-1], border is found.
//           store the  beginning position of border */
//        i--;j--;
//        bpos[i] = j; //пишем начало и конец следующего суффикса
//    }
//}
//
////Preprocessing for case 2
//void preprocess_case2(int *shift, int *bpos, string pat, int m)
//{
//    int i, j;
//    j = bpos[0];
//    for(i=0; i<=m; i++)
//    {
//        /* set the border position of the first character of the pattern
//           to all indices in array shift having shift[i] = 0 */
//        if(shift[i]==0)
//            shift[i] = j;
//
//        /* suffix becomes shorter than bpos[0], use the position of
//           next widest border as value of j */
//        if (i==j)
//            j = bpos[j];
//    }
//}
//
///*Search for a pattern in given text using
//  Boyer Moore algorithm with Good suffix rule */
//void search(string text, string pat)
//{
//    // s is shift of the pattern with respect to text
//    int s=0, j;
//    int m = pat.length();
//    int n = text.length();
//
//    int bpos[m+1], shift[m+1];
//
//    //initialize all occurrence of shift to 0
//    for(int i=0;i<m+1;i++) shift[i]=0;
//
//    //do preprocessing
//    preprocess_strong_suffix(shift, bpos, pat, m);
//    cout<<"l";
//    preprocess_case2(shift, bpos, pat, m);
//
//    while(s <= n-m)
//    {
//
//        j = m-1;
//
//        /* Keep reducing index j of pattern while characters of
//             pattern and text are matching at this shift s*/
//        while(j >= 0 && pat[j] == text[s+j])
//            j--;
//
//        /* If the pattern is present at the current shift, then index j
//             will become -1 after the above loop */
//        if (j<0)
//        {
//            printf("pattern occurs at shift = %d\n", s);
//            s += shift[0];
//        }
//        else
//            /*pat[i] != pat[s+j] so shift the pattern
//              shift[j+1] times  */
//            s += shift[j+1];
//    }
//
//}
//
//////Driver
//int main()
//{
//    string text = "GCATCGCAGAGAGTATACAGTACG";
//    char pat[] = "ABBABAB";
//    search(text, pat);
//    return 0;
//}


//int main(){
//    string s = "MURMUR";
//    int m = s.length();
//    std::vector<int> suffshift(m + 1, m);
//    std::vector<int> z(m, 0);
//    for (int j = 1, maxZidx = 0, maxZ = 0; j < m; ++j) {
//
//        if (j <= maxZ) z[j] = std::min(maxZ - j + 1, z[j - maxZidx]);
//
//        while (j + z[j] < m && s[m - 1 - z[j]] == s[m - 1 - (j + z[j])]) z[j]++;
//        if (j + z[j] - 1 > maxZ) {
//            maxZidx = j;
//            maxZ = j + z[j] - 1;
//        }
//    }
//
//    for (int j = m - 1; j > 0; j--) suffshift[m - z[j]] = j;
//    //цикл №1
//    for (int j = 1, r = 0; j <= m - 1; j++) //цикл №2
//        if (j + z[j] == m)
//            for (; r <= j; r++)
//                if (suffshift[r] == m) suffshift[r] = j;
//
//    for (int i =0;i<suffshift.size();i++) cout<<endl;
//}


//void preBmBc(int* x, string pat){
//    int m = pat.length();
//    for (int i =0; i<100;i++){
//        x[i]=m;
//    }
//
//    for (int i =0; i<=m-2;i++){
//        x[pat[i]]=m-1-i;
//    }
//}
//
////bool isPrefix(string pattern, int p){
////    int m = pattern.length();
////    int j =0;
////    for(int i=p; p<=m-1;i++){
////        if (pattern[i]!=pattern[j]){
////            return false;
////        }
////        j++;
////    }
////    return true;
////}
//
//bool isPrefix(string pattern, int p) { //p - где начинается суффикс. И проверяет является ли он префиксом
//    int m = pattern.size();
//    for (int i = 0; i < m - p; i++) {
//        if (pattern[i+p] != pattern[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int maxLengthOfSuffix(std::string x, int p) {
//
//    int maxLen = 0;
//    int lenX = x.length();
//    for (int i = 0; i < lenX; i++) {
////        cout<<x.substr(0, i)<<" "<<p<<endl; //с какого индекса сколько символов с 0 i символов
////        cout<<x.substr(lenX - i, i)<<" "<<p<<endl;
////        cout<<endl;
//        if (x.substr(0, i) == x.substr(lenX - i, i) && i <= p) {
//            maxLen = i;
//        }
//    }
////    cout<<p<<" "<<maxLen<<endl;
////    cout<<endl;
//    return maxLen;
//}
//
//void preBmGs( int* bmGs,string pattern ){
//    int m = pattern.length();
//    int lastPrefixPosition= m;
//    for (int i = m-1; i>=0; i--){
//        if (isPrefix(pattern, i+1))
//            lastPrefixPosition=i+1;
//
//        bmGs[m-1-i]=lastPrefixPosition-i+m-1;
//    }
//    for (int i =0; i<=m-2; i++){
//        int slen = maxLengthOfSuffix(pattern,i);
//        bmGs[slen]=m-1-i+slen;
//    }
//};
//
//void BM(string text,string pattern){
//    vector <int> answer;
//    int m = pattern.length();
//    int n = text.length();
//
//    int bmBc[100];
//    int bmGs[6];
//
//    preBmBc(bmBc, pattern);
//    cout<<"dad";
//    preBmGs(bmGs, pattern);
//
//    for(int i = m-1; i<=n-1; i++ ){
//        int j = m-1;
//        while(pattern[j]==text[i]){
//            if (j==0) answer.push_back(i);
//        i--;
//        j--;
//        }
//        i+=max(bmGs[m-1-j], bmBc[text[i]]);
//    }
//    for (int i =0; i<answer.size();i++){
//        cout<<answer[i]<<endl;
//    }
//}
//
//int main(){
////   BM("GCATCGCAGAGAGTATACAGTACG","MURMUR");
//   string pattern ="abacaba";
//   vector<int> out;
//   for (int i = 0; i<pattern.length();i++){
//       out.push_back(maxLengthOfSuffix(pattern,i));
//   }
////
//    for (int i =0;i<out.size();i++) cout<<out[i]<<" ";
////int p =1;
////string a ="abacaba";
////   cout<<maxLengthOfSuffix(a,p);
//   // cout<<isPrefix(a,p);
//}





















//bool RabinKarpSearch(string txt, string pat, int CountEqual, int d, int h, int p, int q)
//{
//    int M = pat.length();
//    int N = txt.length();
//    int i, j;
//    int t = 0;
//    int CountScore=0;
//
//    for (i = 0; i < M; i++) {
//        // p = ( p + pat[i]);
//        t = ( d*t + txt[i])%q;
//    }
//
//    for (i = 0; i <= N - M; i++) {
//
//        if (p == t) {
//
//            for (j = 0; j < M; j++) {
//                if (txt[i + j] != pat[j]) {
//                    break;
//                }
//            }
//
//            if (j == M) {
//                CountScore++;
//                if (CountScore==CountEqual) return true;
//            }
//
//        }
//
//        if (i < N - M) {
//            t = (d*(t - txt[i]*h)  + txt[i + M])%q ;
////            if (t<0) t = (t+q);
//        }
//    }
//    return false;
//}
//
//void RabinKarp(string patternOne, int NOne, string patternTwo, int NTwo){
//    auto start = chrono::steady_clock::now();
//
//    long int hash_p1, hash_p2 ;
//    long int h1,h2 ;
//    int q =65713;
//    int d = 52;
//    h1 = int (pow(d, patternOne.length()-1))%q;
//
//
//    for (int i =0; i<patternOne.length();i++) hash_p1= (patternOne[i]+d*hash_p1)%q;
//
//
//    for (int i=0; i<1;i++) {
//        if (RabinKarpSearch("BAOBABS", patternOne, NOne,d,h1,hash_p1,q)) {
//            h2 = int (pow(d, patternTwo.length()-1))%q;
//            for (int i =0; i<patternTwo.length();i++) hash_p2= (patternOne[i]+d*hash_p2)%q;
//            if(RabinKarpSearch("BARBERSHOP", patternTwo, NTwo, d,h2,hash_p2,q)) {
//                cout<<"lol"<<endl;
//            };
//        };
//
//    }
//
//}
//
//
//int main(){
//    RabinKarp("BAOBAB",1,"BARBERSHOP",1);
//}



//# include<iostream>
//# include<string>
//using namespace std;
//// Самая длинная длина совпадения
//# define MAX_SIZE 1000
//
//
//// Получение расстояния перемещения суффиксного правила
//int GoodSuffix(int j, string& pat) {
//    int terminal = pat.length() - 1;
//    int index = -1;
//    j--;
//    while (j >= 0) {
//        if (pat[j] == pat[terminal]) {
//            index = j;
//            break;
//        }
//        else j--;
//    }
//    return terminal - index;
//}
//// Получаем расстояние перемещения правила плохого символа
//int BadChar(int j,char temp,string str)
//{
//
//    int index = -1;
//    for (int i = j - 1; i >= 0; --i)
//    {
//        if (str[i] == temp)
//        {
//            index = i;
//            break;
//        }
//    }
//    return j - index;
//}
//int BM(string source, string target)
//{
//    int i = 0, j = 0, soulen = source.length (), tarlen = target.length (); // инициализация
//    int badvalue = 0, distance = 0;
//    if (soulen <tarlen) {// Сравните длину
//        return -1;
//    }
//
//    i = tarlen-1; j = tarlen-1; // совпадение с конца
//
//    while (i < soulen) {
//        if (source [i] == target [j]) {// совпадение символов успешно
//            if (j == 0) {
//                return i;
//            }
//
//            i--; j--;
//        }
//        else {// Не найдено успешно
//            if (j == tarlen-1) {// Если последний символ не соответствует успешно, "правило плохого символа"
//                badvalue = BadChar(j, source[i],target);
//
//                i = i + tarlen - 1 - j + badvalue;
//                j = tarlen - 1;
//            }
//            else {// имеет суффикс, сравните "правила плохих символов" и "правила суффиксов"
//                badvalue = BadChar(j, source[i], target);
//                if (badvalue == -1)
//                    badvalue = target.length();
//                distance = badvalue > GoodSuffix(j,target) ? badvalue : GoodSuffix(j, target);
//
//                i = i + tarlen-1-j + distance; // Обновляем позицию i
//                j = tarlen-1; // Обновляем позицию j
//
//            }
//        }
//    }
//}
//int main()
//{
//    // Таблица хороших суффиксов: сохраняет расстояние перемещения целевой строки вправо, когда встречается хороший суффикс.
//    int* goodSuffix = new int[MAX_SIZE];
//    string model = "THERE IS A SIMPLE EXAMPLE";
//    string str = "EXAMPLE";
//
//
//    cout <<  BM (model, str) << endl;
//    delete[]goodSuffix;
//    return 0;
//}
#include <iostream>
#include <vector>

#define SHIFT_SIZE 256
#define uichar (int)(unsigned char)

void getBadShift(int shift[], std::string& str) {
    int pattern_size = str.size();

    for (int i = 0; i < SHIFT_SIZE; i++) {
        shift[i] = pattern_size;
    }

    for (int i = 0; i < pattern_size - 1; i++) {
        shift[uichar str[i]] = pattern_size - i - 1;
    }
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int getIndexShift(std::string& str, int str_ind, int count) {
    int n = str.size();
    int i = n - 1, j = str_ind;
    while (str_ind >= 0) {
        i = n-1; j = str_ind;
        if (str_ind < count-1) count = str_ind+1;
        while (i >= n - count && str[i] == str[j]) {
            if (n - i == count) return (n - j - count);
            i--;
            j--;
        }
        str_ind--;
    }
    return n;

}

void getGoodShift(int* shift, std::string& str) {
    int len = str.size();
    int str_ind = len - 2;

    for (int count = 1; count < len; count++) {
        shift[count] = getIndexShift(str, str_ind, count);
        str_ind = len - shift[count] - 1;
    }

}

bool isInString(std::string& txt, std::string& pat, int times, int *g_shift, int b_shift[]) {
    int pat_size = pat.size(), txt_size = txt.size();
    int d1, d2; //для вычисления сдвигов
    //кол-во найденных / кол-во совпавших символов
    int i, j, k, count = 0, match = 0;
    i = j = k = pat_size - 1; // i - тек.позиция откуда начинаем проверку в тексте, j - бегунок в паттерне, k - бегунок в тексте
    while (i <= txt_size - 1) {
        match = 0;
        j = pat_size - 1;
        k = i;
        while (j >= 0 && pat[j] == txt[k]) {
            k--; j--;
            match++;
        }

        //если нашли, то прибавляем к счётчику 1 и сдвигаемся на длину паттерна
        if (k + pat_size == i) {
            count++;
            i += pat_size;
        }
        else {
            d1 = max(b_shift[uichar txt[i]] - match, 1);
            d2 = *(g_shift + match);
            if (count == 0) i += d1;
            else i += max(d1, d2);
        }
    }
    if (count == times) return true; //если паттерн найден в тексте заданное кол-во раз, то ТРУЕ
    else return false;
}

void MyBoer( std::string& name_pat, int name_times, std::string& subj_pat, int subj_times) {
    int bad_shift_name[SHIFT_SIZE];
    //int* good_shift_name = new int[name_pat.size()]; good_shift_name[0] = 1;
    int good_shift_name[name_pat.size()];
    good_shift_name[0]=1;

    getGoodShift(good_shift_name, name_pat);
    getBadShift(bad_shift_name, name_pat);

    int bad_shift_subj[SHIFT_SIZE];
    int* good_shift_subj = new int[subj_pat.size()]; good_shift_subj[0] = 1;
    getGoodShift(good_shift_subj, subj_pat);
    getBadShift(bad_shift_subj, subj_pat);

    string b = "GCATCGCAGAGAGTATACAGTACG";
    cout<<isInString(b,name_pat,1,good_shift_name,bad_shift_name);

}


int main(){
    string name = "GCAGAGAG";
    string name1 = "GCAGAGAG";

    MyBoer(name,1,name,1);
}