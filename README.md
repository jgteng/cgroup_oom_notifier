# cgroup_oom_notifier
cgroup oom notifier

maven package之后生成的native-oom-notifier-1.0-SNAPSHOT-linux-x86.jar包内不包含libnative-oom-notifier.so，
需要手动将target/test-classes/META-INF下的native目录放到jar包的META-INF下