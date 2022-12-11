/*Boot1    Boot0
    X       0           st-Link下载在flash启动
    0       1           UART下载，在下载完代码后需要将boot0接回低电平
    1       1           在SRAM启动
*/   