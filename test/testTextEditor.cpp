#include <gtest/gtest.h>
#include "TextEditorH.h"

TEST(TextEditor, positionpos) {
  TextEditor pos;
  ASSERT_NO_THROW(pos.position(5, 5));
}

TEST(TextEditor, positionneg) {
  TextEditor pos;
  ASSERT_ANY_THROW(pos.position(-5, -5));
}

TEST(TextEditor, constructorinitialization) {
  ASSERT_NO_THROW(TextEditor t(45, 18,10));
}

TEST(TextEditor, constructordeff) {
  ASSERT_NO_THROW(TextEditor t());
}

TEST(TextEditor, stroka) {
  TextEditor t;
  ASSERT_NO_THROW(t.show("test",1,1));
}