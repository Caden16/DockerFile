#使用的基础镜像
FROM ubuntu:14.04
#作者
MAINTAINER TEST
#配置
RUN apt-get update
RUN apt-get install -y openssh-server
RUN mkdir -p /var/run/sshd
RUN mkdir -p /root/.ssh
#添加文件
ADD authorized_keys /root/.ssh/authorized_keys
ADD run.sh /root/run.sh
RUN chmod 755 /root/run.sh
#导出端口
EXPOSE 22
#设置默认启动命令
CMD ["/root/run.sh"]
