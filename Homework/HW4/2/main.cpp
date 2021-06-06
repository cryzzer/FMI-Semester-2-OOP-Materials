#include <iostream>

#include "Document.hpp"
#include "KeyValueDatabase.hpp"
#include "Object.hpp"

// write_line, read_line(), read_line(x) test
void test1() {
  Document temp("temp", "/tmp", "doc");
  temp.write_line("This is an example doc");
  temp.write_line("This is another example line");
  temp.write_line("This is a third example line");
  temp.write_line("This is a forth example line");
  std::cout << temp.read_line() << std::endl;   // This is an example doc
  std::cout << temp.read_line() << std::endl;   // This is another example line
  std::cout << temp.read_line(3) << std::endl;  // This is a third example line
  std::cout << temp.read_line() << std::endl;   // This is a forth example line
  std::cout << temp.read_line(1) << std::endl;  // This is an example doc
  std::cout << temp.read_line() << std::endl;   // This is another example line
}

// operator== and operator!= tests
void test2() {
  Document test2("file", "/C", "pdf");
  test2.write_line("first line");
  test2.write_line("second line");
  test2.write_line("third line");
  test2.write_line("fourth line");
  test2.write_line("fifth line");
  test2.write_line("sixth line");

  Document otherDoc("otherfile", "/D", "pdf");
  otherDoc.write_line("first line");
  otherDoc.write_line("second line");
  otherDoc.write_line("third line");
  otherDoc.write_line("fourth line");
  otherDoc.write_line("fifth line");

  if (test2 == &otherDoc) {
    std::cout << "wait, that's illegal ?!?\n";
  } else {
    std::cout
        << "yes, they are not equal because the second doc has 1 less line\n";
  }

  otherDoc.write_line("sixthhhh line");

  if (test2 == &otherDoc) {
    std::cout << "wait, that's illegal (2 second time) ?!?\n";
  } else {
    std::cout << "yes, they are not equal because the second doc has different "
                 "last line\n";
  }

  otherDoc.changeLine(5,"sixth line");

  if (test2 != &otherDoc) {
    std::cout << "wait, that's illegal (3 third time) ?!?\n";
  } else {
    std::cout << "yes, they are equal\n";
  }
}

// test to_string, from_string and debug_print
void test3() {
  Document test("somewhere", "Computer", "exe");

  test.write_line("Movies I like:");
  test.write_line("Star Wars");
  test.write_line("Lord of the Rings");
  test.write_line("Saw");
  test.write_line("Hobbit");
  test.write_line("Marvel movies");

  std::cout << test.to_string();

  std::string temp =
      "somewhere else\nComputer\ndoc\nGenres I "
      "like:\nFantasy\nHorror\nAction\nComedy\nDrama\nThriller\nand many "
      "more\n";

  test.from_string(temp);

  std::cout << "\n\nchanged:\n=======================\n\n";
  std::cout << test.to_string();
  std::cout << "\n\ndebugger:\n=======================\n\n";

  std::cout << test.debug_print();
}

void test4() {  // test add_entry and get_value
  KeyValueDatabase test("Safe", "Secret Place", ".zip");

  test.add_entry(std::pair<std::string, int>("pass1", 69));
  test.add_entry(std::pair<std::string, int>("pass2", 420));
  test.add_entry(std::pair<std::string, int>("pass3", 3));
  test.add_entry(std::pair<std::string, int>("pass4", 101));
  test.add_entry(std::pair<std::string, int>("pass5", 7));

  std::cout << "420 value : " << test.get_value("pass2") << std::endl;

  try {
    std::cout << test.get_value("random text") << std::endl;
  } catch (...) {
    std::cout << "The key does not match with any of the keys in the system!\n";
  }
}

void test5() {  // test operator==
  KeyValueDatabase test("First secret Name", "first secret place", "sec");
  test.add_entry(std::pair<std::string, int>("pass1", 69));
  test.add_entry(std::pair<std::string, int>("pass2", 70));
  test.add_entry(std::pair<std::string, int>("pass3", 71));

  KeyValueDatabase otherTest("Second secret Name", "Second secret place",
                             "sec");
  otherTest.add_entry(std::pair<std::string, int>("pass1", 69));
  otherTest.add_entry(std::pair<std::string, int>("pass2", 70));

  std::cout << "\n\nTest1\n========================\n\n";

  if (test == &otherTest) {
    std::cout << "Thats illegal ! (1)";
  } else {
    std::cout << "yes, different because  3 != 2 elements\n";
  }

  otherTest.add_entry(std::pair<std::string, int>("pass3", 71));

  std::cout << "\n\nTest2\n========================\n\n";

  if (test == &otherTest) {
    std::cout << "yes they are equal";
  } else {
    std::cout << "Thats illegal ! (1)";
  }
}

void test6() {  // test operator!=
  KeyValueDatabase test("First secret Name", "first secret place", "sec");
  test.add_entry(std::pair<std::string, int>("pass1", 69));
  test.add_entry(std::pair<std::string, int>("pass2", 70));
  test.add_entry(std::pair<std::string, int>("pass3", 71));

  KeyValueDatabase otherTest("Second secret Name", "Second secret place",
                             "sec");
  otherTest.add_entry(std::pair<std::string, int>("pass1", 69));
  otherTest.add_entry(std::pair<std::string, int>("pass2", 70));
  otherTest.add_entry(std::pair<std::string, int>("random", 420));

  std::cout << "\n\nTest1\n========================\n\n";

  if (test != &otherTest) {
    std::cout << "yes different, because last elements are different\n";
  } else {
    std::cout << "Wait, thats illegal!\n";
  }
}

//test debug_print , to_string and from_string
void test7() {
  KeyValueDatabase test("Top", "Secret", "rar");

  test.add_entry(std::pair<std::string, int>("pass1", 69));
  test.add_entry(std::pair<std::string, int>("pass2", 420));
  test.add_entry(std::pair<std::string, int>("pass3", 3));
  test.add_entry(std::pair<std::string, int>("pass4", 101));
  test.add_entry(std::pair<std::string, int>("pass5", 7));

  std::cout << test.to_string() << "\n\n\n\n\n";

  std::string temp = "Word\nC:\nexe\nfmi1:12\nfmi2:69\nfmi3:420\n";

  test.from_string(temp);

  std::cout << "\n\nafter updating:\n=========================\n\n";
  std::cout << test.to_string() << "\n\n\n\n\n";

  std::cout << "\n\ndebugging\n=========================\n\n";
  std::cout << test.debug_print() << "\n\n\n\n\n";
}

int main() {
  test7();
  //
}