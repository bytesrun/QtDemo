#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QLabel label("Hello, World");
	label.show();
	
	QFileSystemModel model;
	model.setRootPath(QDir::currentPath());
	
	QTreeView tree;
	tree.setModel(&model);
	tree.setRootIndex(model.index(QDir::currentPath()));
	
	QListView list;
	list.setModel(&model);
	list.setRootIndex(model.index(QDir::currentPath()));
	
	list.show();
	tree.show();
	
	app.exec();
}