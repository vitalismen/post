#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QString>
#include "../src/doc_image.h"
#include "../src/functions.h"

using namespace testing;

TEST(test001, gtests)
{
//    doc_image doc1(img_status::in_foto);
//    doc1.set_image(QImage(), "aaddrreess", "nnuummbbeerr", img_status::in_foto);
//    doc1.set_uniq("uunniicc");
//    EXPECT_EQ("in_aaddrreess", doc1.get_adr());
//    EXPECT_EQ("uunniicc", doc1.get_uniq());
//    EXPECT_EQ("nnuummbbeerr", doc1.get_number_doc());
//    EXPECT_EQ("in", doc1.get_type());
}
TEST(test002, gtests)
{
    doc_image doc1(img_status::in_foto);
    doc1.set_adr("aaddrreess");
    doc1.set_number_doc("nnuummbbeerr");
    doc1.set_uniq("uunniicc");
    EXPECT_EQ("in_aaddrreess", doc1.get_adr());
    EXPECT_EQ("uunniicc", doc1.get_uniq());
    EXPECT_EQ("nnuummbbeerr", doc1.get_number_doc());
    EXPECT_EQ("in", doc1.get_type());
}
TEST(test003, gtests)
{
    doc_image doc1(img_status::in_foto);
    doc1.set_image(QImage(), "aaddrreess", "nnuummbbeerr", img_status::in_foto);
    doc_image doc2(img_status::in_foto);
    doc2.set_image(QImage(), "aaddrreess2", "nnuummbbeerr2", img_status::in_foto);
    doc1.set_uniq("uunniicc");
    EXPECT_EQ(doc1.get_image(), doc2.get_image());
}
TEST(test004, gtests)
{
//    doc_image doc1(img_status::in_foto);
//    doc1.set_image(QImage(), "aaddrreess", "nnuummbbeerr", img_status::in_foto);
//    doc_image doc2(img_status::in_foto);
//    doc2.set_image(QImage(), "aaddrreess2", "nnuummbbeerr2", img_status::in_foto);
//    doc1.set_uniq("uunniicc");
//    EXPECT_EQ(doc1.get_adr(), doc2.get_adr());
}
TEST(test005, gtests)
{
    QString tmp_str{"movcksv45 67e88-797685 nfvisn lskdfnm ьщвамьтыо K:MN 097896_))(  ЩДШТО"};
    QString instr = my::base64_plus(tmp_str);
    QString tmp_str2 = my::base64_minus(instr);
    EXPECT_EQ(tmp_str, tmp_str2);
}
TEST(test006, gtests)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
