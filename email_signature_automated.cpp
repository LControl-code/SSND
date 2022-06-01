#include <cctype> // tolower
#include <cstdio> // fopen. fclose, freopen
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string lowercase_name();
string file_name();
string uppercase_role();

string name = {}, surname = {}, role = {},
       personal_telephone = {}; // * holds the values
string shop_telephone = "032/222 55 55", shop_name = "Error s.r.o",
       shop_adress = "Vajanského 4", email, shop_town = "91101 Trenčín",
       shop_country = "Slovensko", shop_website = "error.sk";
bool personal_tel_bool = false;

// ! Too many global variables, you should create an object for this
// TODO: create a menu to change all of these parameters, the default one should
// be one other screen
int main() {

  fstream file_W(file_name(), ios::out);

  int exit_code = EXIT_FAILURE;

  // TODO: Refactor it so it works only when it creates new file (fopen)
  if (!file_W) {
    cout << "File not created or not opened." << endl;
    return exit_code;
  } else {
    cout << "File created successfully" << endl;
    exit_code = EXIT_SUCCESS;
  }

  if (!exit_code) {

    file_W << "<!DOCTYPE html\n\tPUBLIC \"-//W3C//DTD XHTML 1.0 "
              "Transitional//EN\" "
              "\"http://www.w3.org/TR/xhtml1/DTD/"
              "xhtml1-transitional.dtd\">\n<html "
              "xmlns=\"http://www.w3.org/1999/xhtml\">";

    file_W << "\n\n<head>\n<meta http-equiv=\"Content-Type\" "
              "content=\"text/html; charset=UTF-8\"/>"
           << "\n<title>" << name << " " << surname
           << "</title>\n<meta name=\"viewport\" content=\"width=device-width, "
              "initial-scale=1.0\" />\n<style type=\"text/css\">\n\t@font-face "
              "{\n\t\tfont-family: 'Titillium';\n\t\tfont-style: "
              "normal;\n\t\tfont-weight: 400;\n\t\tsrc: "
              "url('https://fonts.googleapis.com/"
              "css?family=Titillium+Web');\n}\n</style>\n</head>"
           << endl;

    file_W << "\n<body style=\"margin: 0; padding: 0; font-family: "
              "'Titillium', sans-serif;color:#003e6e\">\n"
           << endl;
    file_W
        << "<div style=\"display: none; max-height: 0px; overflow: hidden;\">";
    file_W
        << "\n\t&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;"
           "&#"
           "847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&"
           "nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;"
           "&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;"
           "&#"
           "847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&"
           "nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;"
           "&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;"
           "&#"
           "847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&"
           "nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;"
           "&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;"
           "&#"
           "847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&"
           "nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;"
           "&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;"
           "&#"
           "847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&"
           "nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;"
           "&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;"
           "&#"
           "847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&"
           "nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;"
           "&"
           "zwnj;&nbsp;&#847;&zwnj;&nbsp;&#847;&zwnj;&nbsp;\n</div>"
        << endl;

    file_W << "\n<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" "
              "width=\"100%\" style=\"max-width:450px\">\n<tr>\n<td "
              "style=\"width:180px;\">\n<a href=\"http://www.error.sk\" "
              "target=\"_blank\"><img "
              "src=\"https://image.ibb.co/fPOjh9/logo.png\" width=\"180p\" "
              "alt=\"logo\"></a>\n</td>\n<td>\n<table style=\"padding-left: "
              "25px;border-left:2px solid #002e6e\">\n<tr>\n<td colspan=\"2\" "
              "style=\"padding-left: 6px;\">";

    file_W
        << "<a \nstyle=\"margin:0px 0 0 0;text-decoration: none;font-weight: "
           "bold;font-size:1.2rem;display:block;color:#002e6e !important\">"
        << name << " " << surname
        << "</a>\n<a \nstyle=\"text-transform: uppercase;text-decoration: "
           "none;margin:0 0 20px 0;font-size:.8rem;color:#002e6e "
           "!important;display:block\">"
        << role << "</a>";

    if (personal_tel_bool) {
      file_W << "<tr>\n<td><img src=\"https://thumb.ibb.co/hxCD9p/mobile.png\" "
                "alt=\"personal "
                "mobile\"\nstyle=\"display:inline;width:27px;margin-top: "
                "-1px;margin-left:1px\"> </td>\n<td><a href=\"tel:"
             << personal_telephone
             << "\" style=\"color:#002e6e;text-decoration: "
                "none;font-size:.8rem\">"
             << personal_telephone << "</a></td>\n</tr>";
    }

    file_W << "\n</tr>\n<td><img src=\"https://i.ibb.co/D1WChxW/phone.png\" "
              "alt=\"mobile\" \nstyle=\"display:inline;width:27px;margin-top: "
              "4px;transform:rotate(35deg);-webkit-transform:rotate(35deg);"
              "margin-left:1px;\">\n</td>\n\n<td><a href=\"tel:"
           << shop_telephone
           << "\" "
              "style=\"color:#002e6e;text-decoration: "
              "none;font-size:.8rem\">"
           << shop_telephone << "</a>\n</td>";

    file_W << "\n<tr>\n<td> <img src=\"https://thumb.ibb.co/fuzApp/mail.png\" "
              "alt=\"mail\"\nstyle=\"display:inline;width:30px;margin-top: "
              "-2px;\"></td>\n<td> <a href=\"mailto:"
           << email
           << "\" target=\"_top\"\nstyle=\"color:#002e6e;text-decoration: "
              "none;font-size:.8rem\">"
           << email << "</a></td>\n</tr>";

    file_W << "\n<tr>\n<td style=\"display: block\"> <img "
              "src=\"https://thumb.ibb.co/e5j4FU/map.png\" alt=\"map\" "
              "border=\"0\" "
              "alt=\"map\"\nstyle=\"display:inline;width:30px;margin-top: "
              "-6px;\"></td>\n<td> <a "
              "href=\"https://g.page/"
              "Errorservistrencin\"\nstyle=\"color:#002e6e;text-decoration: "
              "none;float:left;font-size:.8rem\" target=\"_blank\">"
           << shop_name << "<br>" << shop_adress << "<br>" << shop_town
           << "<br>" << shop_country << "</a></td>\n</tr>";

    file_W
        << "\n<tr>\n<td style=\"display: block\"> <img "
           "src=\"https://i.ibb.co/HKkqKcW/weba.png\" alt=\"web\" border=\"0\" "
           "alt=\"map\"\nstyle=\"display:inline;width:30px;margin-top: "
           "-4px;\"></td>\n<td> <a href=\"https://"
        << shop_website
        << "/\" target=\"_blank\"\nstyle=\"color:#002e6e;text-decoration: "
           "none;float:left;font-size:.8rem\">"
        << shop_website << "</td>\n</tr>";

    file_W << "\n</table>\n</td>\n</tr>\n</table>";

    file_W << "<div\nstyle=\"max-width:450px; "
              "height:auto;min-height:40px;margin-left:10px;margin-top:5px;"
              "margin-bottom:10px;display: flex; justify-content: flex-start; "
              "flex-direction:row;\">\n<img "
              "src=\"https://i.ibb.co/cD6gTgX/svg2767.png\" alt=\"leaf icon\" "
              "border=\"0\" height=\"30\" "
              "style=\"margin:5px;\">\n<p\nstyle=\"font-style:italic; "
              "font-size:12px; margin-top: 29px; margin-left: "
              "-9px;margin-bottom:-2px; color:#91c227;\">\nPred vytlačenim "
              "tohto mailu zvážte prosím vplyv na životné "
              "prostredie</p>\n</div>\n</body>\n</html>";
  }

  // " <<  << "
  return 0;
}

string file_name() {
  string name_file;

  cout << "Enter the name and surname: ";

  cin >> name >> surname;
  cout << "Enter the role of " << name << " " << surname << ": ";

  cin.ignore();
  getline(cin, role);
  role = uppercase_role();
  name_file = name + "_" + surname + ".html";

  email = lowercase_name() + "@error.sk";
  cout << "Is this the correct email: " << email << " (Y/n): ";

  char answer_y_n;
  cin >> answer_y_n;

  switch (answer_y_n) {
  case 'y':
  case 'Y':
    cout << "Email is correct." << endl;
    break;
  case 'N':
  case 'n':
    cout << "Enter the correct email: ";
    cin >> email;
    break;
  default:
    cout << "Incorrect input, default option (" << email << ")" << endl;
  }

  cout << "Do you want to add personal telephone? (Y/n): ";
  cin >> answer_y_n;
  switch (answer_y_n) {
  case 'y':
  case 'Y':
    cout << "Enter the personal telephone: ";
    cin.ignore();
    getline(cin, personal_telephone);
    //// cin >> personal_telephone;
    personal_tel_bool = true;
    break;
  case 'N':
  case 'n':
    cout << "Personal telephone is not added." << endl;
    personal_tel_bool = false;
    break;
  default:
    cout << "Incorrect input, default option (n)" << endl;
    personal_tel_bool = false;
  }

  return name_file;
}

string lowercase_name() {

  string low_name = name, low_surname = surname;
  low_name[0] = (char)tolower(low_name[0]);
  low_surname[0] = (char)tolower(low_surname[0]);

  return low_name + '.' + low_surname;
}

// uppercase every character in string name and surname
// all characters in name and surname are uppercase
string uppercase_role() {

  string up_role = role;
  for (int i = 0; i < role.length(); i++) {
    up_role[i] = (char)toupper(role[i]);
  }

  return up_role;
}