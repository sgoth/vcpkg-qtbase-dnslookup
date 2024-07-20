
#include <QCoreApplication>
#include <QDebug>
#include <QDnsLookup>
#include <QHostAddress>

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	QDnsLookup lookup(QDnsLookup::A, "www.github.com");
	QObject::connect(&lookup,
									 &QDnsLookup::finished,
									 [&lookup]()
									 {
										 if (lookup.error() != QDnsLookup::NoError)
										 {
											 qDebug() << "DNS lookup failed: " << lookup.error();
											 QCoreApplication::exit(1);
										 }

										 auto records = lookup.hostAddressRecords();
										 for (const auto& record : records)
										 {
											 qDebug() << record.timeToLive() << "; " << record.value() << '\n';
										 }
										 QCoreApplication::quit();
									 });
	lookup.lookup();
	return a.exec();
}
