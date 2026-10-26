/******************************
* Строки, векторы и словари   *
* Вариант 11                  *
* Колосков Дмитрий Викторович *
******************************/

#include <iostream>
#include <string>
#include <cctype> 
#include <vector>
#include <map>

using namespace std;

int main() {
  /****
  * A *
  ****/
  string userInput;
  string readyMadeString = "";

  cout << "Enter the string that needs to be reformatted: ";

  if(!(getline(cin, userInput)) || userInput.length() > 200) {
    cout << "INVALID";
    return 0;
  }

  for(const auto& symbol: userInput) {
    if(isalpha(symbol)){
      if(islower(symbol)) {
        readyMadeString += toupper(symbol);
      } else {
        readyMadeString += tolower(symbol);
      }
    } else {
      readyMadeString += symbol;
    }
  }

  cout << "\nAnswer: " << readyMadeString << "\n\n";

  /****
  * B *
  ****/
  vector<int> userVector, tempVector;
  int countElementVector, tempElement;


  cout << "Enter the number of elements in the vector: ";

  if(!(cin >> countElementVector) || countElementVector < 0 || countElementVector > 100) {
    cout << "INVALID";
    return 0;
  }

  for(int rowIndex = 0; rowIndex < countElementVector; ++rowIndex) {
    cout << "Enter an element " << rowIndex + 1 << ": ";
    if(!(cin >> tempElement) || abs(tempElement) > 1000) {
      cout << "INVALID";
      return 0;
    } else {
      userVector.push_back(tempElement);
    }
  }

  cout << "Vector useer: ";

  for(const auto& symbol: userVector) {
    cout << symbol << ' ';
  }

  if(userVector.size() == 0) {
    cout << "EMPTY";
    return 0;
  }

  for(int rowIndex = 1; rowIndex < userVector.size(); ++rowIndex) {
    tempVector.push_back(userVector[rowIndex]);
  }

  tempVector.push_back(userVector[0]);
  userVector = tempVector;

  cout << "\nAnswer: ";

  for(const auto& symbol: userVector) {
    cout << symbol << ' ';
  }

  /****
  * C *
  ****/
  map<string, int> userMap;
  int countElementMap, meaningMap;
  string keyMap, exclusionKey;

  cout << "\n\nEnter the number of dictionary elements: ";

  if(!(cin >> countElementMap) || countElementMap < 0) {
    cout << "INVALID";
    return 0;
  }

  cout << "Enter the dictionary keys and values:\n";

  for(int rowIndex = 0; rowIndex < countElementMap; ++rowIndex) {
    cout << "Enter the key value: "; cin >> keyMap;
    cout << "Enter its value: ";     cin >> meaningMap;

    userMap[keyMap] = meaningMap;
  }

  cout << "\nFinal Glossary:\n";

  for(const auto& coupleElements: userMap){
    cout << "Key: "    << coupleElements.first << ' '
         << "Value: "  << coupleElements.second << '\n';
  }

  cout << "\nEnter the key you want to exclude: "; cin >> exclusionKey;

  for(const auto& coupleElements: userMap){
    if(coupleElements.first == exclusionKey) {
      continue;
    }

    cout << "Key: "    << coupleElements.first << ' '
         << "Value: "  << coupleElements.second << '\n';
  }


  /****
  * D *
  ****/
  vector<map<string, string>> locatingObjects;
  int countLocatingObjects;
  string locating, object;
  map<string, vector<string>> grouped;

  cout << "\n\nNumber of records: "; cin >> countLocatingObjects;

  for(int rowIndex = 0; rowIndex < countLocatingObjects; ++rowIndex) {
    cout << "locating = "; cin >> locating;
    cout << "objects = ";  cin >> object;

    locatingObjects.push_back({{"item", locating}, {"place", object}});
  }

  cout << "\nFinal Glossary:";

  for(const auto& vectorElements: locatingObjects){
    cout << "item: "    << vectorElements.at("item") << ' '
         << "place: "  << vectorElements.at("place") << '\n';
  }

  for (const auto& record : locatingObjects) {
    string item = record.at("item");
    string place = record.at("place");
    
    bool existenceElement = false;

    for (const auto& existingElement : grouped[item]) {
        if (existingElement == place) {
            existenceElement = true;
            break;
        }
    }
    
    if (!existenceElement) {
        grouped[item].push_back(place);
    }
  }

  for (const auto& element : grouped) {
    cout << element.first << ": ";

    for (const string& place : element.second) {
        cout << place;
    }
    cout << "\n";
  }

  return 0;
}