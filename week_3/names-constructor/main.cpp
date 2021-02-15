#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct FullName {
    string Name;
    string Soname;
};

class Person {
public:
    Person(const string &first_name, const string &last_name, const int &year) {
        YearNameSoname[year].Name = first_name;
        YearNameSoname[year].Soname = last_name;

        birth_year = year;
    }

    void ChangeFirstName(int year, const string &first_name) {
        if (birth_year > year) {
            return;
        }

        if (YearNameSoname.count(year) == 0) {
            YearNameSoname[year].Soname = "";
        }

        YearNameSoname[year].Name = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        if (birth_year > year) {
            return;
        }

        if (YearNameSoname.count(year) == 0) {
            YearNameSoname[year].Name = "";
        }

        YearNameSoname[year].Soname = last_name;
    }

    string GetFullName(int year) const {
        if (birth_year > year) {
            return "No person";
        }

        if (YearNameSoname.empty()) {
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

    string GetFullNameWithHistory(int year) const {
        if (birth_year > year) {
            return "No person";
        }

        if (YearNameSoname.empty()) {
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
        string secnames_string, firstnames_string;

        if (!secondnames.empty()) {
            secnames_string +=
                    " (" + secondnames[secondnames.size() - 1];
            if (secondnames.size() > 1) {
                for (int i = secondnames.size() - 1; i > 0; --i) {
                    secnames_string += ", " + secondnames[i - 1];
                }
            }
            secnames_string += ")";
        }
        if (!firstnames.empty()) {
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
    int birth_year;
    map<int, FullName> YearNameSoname;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
