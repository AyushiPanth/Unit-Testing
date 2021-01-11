### Syntax

#include "filename.cpp"
#include <gtest/gtest.h>

```
TEST(TestName1, SubTestName1) { 
  // test  
}


Test(TestNam1, SubTestName2) {
  // test 
}

Test(TestName2, SubTestName1) {
  // test
}

int main(int argc, char **argv) {
  testing::INITGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

### Assertives

* Success
* Not-Fatal Failure
  * The execution of test does not stop, it continues after the failure also.
* Fatal Failure
  * The execution of test stops after a failure.



