#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
struct FullName { //создадим структуру из имени и фамилии
    string Name;
    string Soname;
};

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        if (YearNameSoname.count(year) == 0) {
            YearNameSoname[year].Soname = "";
        }

        YearNameSoname[year].Name = first_name; //добавим указанное имя
    }

    void ChangeLastName(int year, const string &last_name) {
        if (YearNameSoname.count(year) == 0) {
            YearNameSoname[year].Name = "";
        }

        YearNameSoname[year].Soname = last_name;
    }

    string GetFullName(int year) {
        if (YearNameSoname.size() == 0) {
            return "Incognito";
        } else {
            for (const auto &i : YearNameSoname) {
                if (year < i.first) {
                    return "Incognito";
                }
                break;
            }
        }
        //иначе
        string nm = "";
        string sn = "";

        for (const auto &i : YearNameSoname) { //полистаем нашу структуру
            //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
            if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
            if (i.first <= year && i.second.Name != "") nm = i.second.Name; //тоже самое с именем
        }

        if (nm == "") {
            return sn + " with unknown first name";
        } else if (sn == "") {
            return nm + " with unknown last name";
        } else {
            return nm + " " + sn;
        }
    }

    string GetFullNameWithHistory(int year) {
        if (YearNameSoname.size() == 0) {
            return "Incognito";
        } else {
            for (const auto &i : YearNameSoname) {
                if (year < i.first) {
                    return "Incognito";
                }

                break;
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        vector<string> secondnames;
        vector<string> firstnames;

        for (const auto &i : YearNameSoname) {
            if (i.first <= year && i.second.Soname != "") {
                if (i.second.Soname != sn && sn != "") {
                    secondnames.push_back(sn);
                }

                sn = i.second.Soname;
            }
            if (i.first <= year && i.second.Name != "") {
                if (i.second.Name != nm && nm != "") {
                    firstnames.push_back(nm);
                }
                nm = i.second.Name;
            }
        }
        string secnames_string = "", firstnames_string = "";

        if (secondnames.size() > 0) {
            secnames_string +=
                    " (" + secondnames[secondnames.size() - 1];
            if (secondnames.size() > 1) {
                for (int i = secondnames.size() - 1; i > 0; --i) {
                    secnames_string += ", " + secondnames[i - 1];
                }
            }
            secnames_string += ")";
        }
        if (firstnames.size() > 0) {
            firstnames_string += " (" + firstnames[firstnames.size() - 1];
            if (firstnames.size() > 1) {
                for (int i = firstnames.size() - 1; i > 0; --i) {
                    firstnames_string += ", " + firstnames[i - 1];
                }
            }
            firstnames_string += ")";
        }
        if (nm == "") {
            return sn + secnames_string + " with unknown first name";
        } else if (sn == "") {
            return nm + firstnames_string + " with unknown last name";
        } else {
            return nm + firstnames_string + " " + sn + secnames_string;
        }
    }

private: 
    map<int, FullName> YearNameSoname;
};