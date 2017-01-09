/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification 
 www.prokarpaty.net
***********************************************************/

#include "GdriveAutotest.h"
#ifdef API_QT_AUTOTEST
#include <QBuffer>
#include <QByteArray>
using namespace googleQt;
using namespace googleQt;

static GdriveRoutes* cl;


static void call_get_from_About(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("About").arg("get");
    std::unique_ptr<gdrive::AboutArg> arg = gdrive::AboutArg::EXAMPLE(0);
    auto res = cl->getAbout()->get(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_create_from_Comments(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Comments").arg("create");
    std::unique_ptr<gdrive::CreateCommentArg> arg = gdrive::CreateCommentArg::EXAMPLE(0);
    std::unique_ptr<comments::Comment> arg2 = comments::Comment::EXAMPLE(0);
    auto res = cl->getComments()->create(*(arg.get()) , *(arg2.get()));
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_deleteOperation_from_Comments(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Comments").arg("deleteOperation");
    std::unique_ptr<gdrive::DeleteCommentArg> arg = gdrive::DeleteCommentArg::EXAMPLE(0);
    cl->getComments()->deleteOperation(*(arg.get()) );
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_get_from_Comments(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Comments").arg("get");
    std::unique_ptr<gdrive::GetCommentArg> arg = gdrive::GetCommentArg::EXAMPLE(0);
    auto res = cl->getComments()->get(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_list_from_Comments(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Comments").arg("list");
    std::unique_ptr<gdrive::CommentListArg> arg = gdrive::CommentListArg::EXAMPLE(0);
    auto res = cl->getComments()->list(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_copy_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("copy");
    std::unique_ptr<gdrive::CopyFileArg> arg = gdrive::CopyFileArg::EXAMPLE(0);
    std::unique_ptr<files::FileResource> arg2 = files::FileResource::EXAMPLE(0);
    auto res = cl->getFiles()->copy(*(arg.get()) , *(arg2.get()));
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_create_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("create");
    std::unique_ptr<gdrive::CreateFileArg> arg = gdrive::CreateFileArg::EXAMPLE(0);
    std::unique_ptr<files::FileResource> arg2 = files::FileResource::EXAMPLE(0);
    auto res = cl->getFiles()->create(*(arg.get()) , *(arg2.get()));
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_createFolder_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("createFolder");
    std::unique_ptr<gdrive::CreateFolderArg> arg = gdrive::CreateFolderArg::EXAMPLE(0);
    auto res = cl->getFiles()->createFolder(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_deleteOperation_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("deleteOperation");
    std::unique_ptr<gdrive::DeleteFileArg> arg = gdrive::DeleteFileArg::EXAMPLE(0);
    cl->getFiles()->deleteOperation(*(arg.get()) );
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_downloadFile_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("downloadFile");
    std::unique_ptr<gdrive::DownloadFileArg> arg = gdrive::DownloadFileArg::EXAMPLE(0);
    QByteArray data("Hello World! 123454321 (.) :: (b -> c) -> (a -> b) -> (a -> c)");
    QBuffer io(&data);
    io.open(QIODevice::ReadOnly);
    cl->getFiles()->downloadFile(*(arg.get()) , &io);
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_emptyTrash_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("emptyTrash");
    std::unique_ptr<gdrive::EmptyTrashArg> arg = gdrive::EmptyTrashArg::EXAMPLE(0);
    cl->getFiles()->emptyTrash(*(arg.get()) );
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_get_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("get");
    std::unique_ptr<gdrive::GetFileArg> arg = gdrive::GetFileArg::EXAMPLE(0);
    auto res = cl->getFiles()->get(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_list_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("list");
    std::unique_ptr<gdrive::FileListArg> arg = gdrive::FileListArg::EXAMPLE(0);
    auto res = cl->getFiles()->list(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_moveFile_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("moveFile");
    std::unique_ptr<gdrive::MoveFileArg> arg = gdrive::MoveFileArg::EXAMPLE(0);
    auto res = cl->getFiles()->moveFile(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_rename_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("rename");
    std::unique_ptr<gdrive::RenameFileArg> arg = gdrive::RenameFileArg::EXAMPLE(0);
    auto res = cl->getFiles()->rename(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_uploadFileMultipart_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("uploadFileMultipart");
    std::unique_ptr<gdrive::MultipartUploadFileArg> arg = gdrive::MultipartUploadFileArg::EXAMPLE(0);
    QByteArray data("Hello World! 123454321 (.) :: (b -> c) -> (a -> b) -> (a -> c)");
    QBuffer io(&data);
    io.open(QIODevice::ReadOnly);
    auto res = cl->getFiles()->uploadFileMultipart(*(arg.get()) , &io);
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_uploadFileSimple_from_Files(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Files").arg("uploadFileSimple");
    QByteArray data("Hello World! 123454321 (.) :: (b -> c) -> (a -> b) -> (a -> c)");
    QBuffer io(&data);
    io.open(QIODevice::ReadOnly);
    cl->getFiles()->uploadFileSimple(&io);
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_create_from_Permissions(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Permissions").arg("create");
    std::unique_ptr<gdrive::CreatePermissionArg> arg = gdrive::CreatePermissionArg::EXAMPLE(0);
    std::unique_ptr<permissions::ResourcePermission> arg2 = permissions::ResourcePermission::EXAMPLE(0);
    auto res = cl->getPermissions()->create(*(arg.get()) , *(arg2.get()));
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_deleteOperation_from_Permissions(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Permissions").arg("deleteOperation");
    std::unique_ptr<gdrive::PermissionArg> arg = gdrive::PermissionArg::EXAMPLE(0);
    cl->getPermissions()->deleteOperation(*(arg.get()) );
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_get_from_Permissions(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Permissions").arg("get");
    std::unique_ptr<gdrive::PermissionArg> arg = gdrive::PermissionArg::EXAMPLE(0);
    auto res = cl->getPermissions()->get(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}

static void call_list_from_Permissions(){
    ApiAutotest::INSTANCE() << QString("%1/%2").arg("Permissions").arg("list");
    std::unique_ptr<gdrive::PermissionListArg> arg = gdrive::PermissionListArg::EXAMPLE(0);
    auto res = cl->getPermissions()->list(*(arg.get()) );
    ApiAutotest::INSTANCE() << "------ RESULT ------------------";
    ApiAutotest::INSTANCE() << res->toString();
    ApiAutotest::INSTANCE() << "--------------------------";
}


static void test_call_AboutRoutes(){
    call_get_from_About();
}

static void test_call_CommentsRoutes(){
    call_create_from_Comments();
    call_deleteOperation_from_Comments();
    call_get_from_Comments();
    call_list_from_Comments();
}

static void test_call_FilesRoutes(){
    call_copy_from_Files();
    call_create_from_Files();
    call_createFolder_from_Files();
    call_deleteOperation_from_Files();
    call_downloadFile_from_Files();
    call_emptyTrash_from_Files();
    call_get_from_Files();
    call_list_from_Files();
    call_moveFile_from_Files();
    call_rename_from_Files();
    call_uploadFileMultipart_from_Files();
    call_uploadFileSimple_from_Files();
}

static void test_call_PermissionsRoutes(){
    call_create_from_Permissions();
    call_deleteOperation_from_Permissions();
    call_get_from_Permissions();
    call_list_from_Permissions();
}


void GdriveAutotest::generateCalls(){
    ApiAutotest::INSTANCE() << "";
    ApiAutotest::INSTANCE() << "============ autotest for module: gdrive ============";
    test_call_AboutRoutes();
    test_call_CommentsRoutes();
    test_call_FilesRoutes();
    test_call_PermissionsRoutes();
}

GdriveAutotest::GdriveAutotest(GoogleClient& c)
{
    cl = c.gdrive();
    cl->autotest();
}
#endif //API_QT_AUTOTEST

