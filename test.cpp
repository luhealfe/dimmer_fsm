#include <iostream>
using namespace std;

int main() {
  const char http_res[] = "HTTP 1.1 200 OK";

  int http_ver = 0;
  int http_status = 0;
  char http_status_msg[128];

  int ret = sscanf(http_res, "HTTP 1.%d %d %s", &http_ver, &http_status, http_status_msg);

  cout << "ret=" << ret << endl;
  cout << "ver=" << http_ver << endl;
  cout << "status=" << http_status << endl;
  cout << "status_msg=" << http_status_msg << endl;

  return 0;
}