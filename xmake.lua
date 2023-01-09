add_rules("mode.debug", "mode.release")

target("Hook")                             -- 默认配置
    set_kind("binary")                           -- 工程名字
    add_files("string/*.cpp")                   -- 编译目标目录





-- target("ImGui_Hook") -- 动态链接库
--     set_kind("binary")
--     add_files("y_ImGui/*.cpp")
--     add_links("z")                      --链接指令
--     add_linkdirs("D:/Adobe/hihsaiuhdis") -- 链接库目录--失败？保留代码 原因未知


