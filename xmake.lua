add_rules("mode.debug", "mode.release")

-- target("Hook")                             -- 默认配置
--     set_kind("binary")                         -- exe程序
--     add_files("string/*.cpp")                   -- 编译目标目录

target("Hook")                             -- 默认配置
    set_kind("shared")                         -- exe程序
    add_files("U_Hook/*.cpp")                   -- 编译目标目录
    add_files("U_Hook/imGui/*.cpp") 
    add_files("U_Hook/include/*.cpp") 
    add_linkdirs("E:/Git/UnrealEngine/Engine/Source/ThirdParty/Windows/DirectX/Lib/x64/") -- 链接库目录
    add_links("d3d11") --库名称




-- target("Hook")                             -- 默认配置
--     set_kind("shared")                     -- DLL程序
--     add_files("string/*.cpp")              -- 编译目标目录


-- target("ImGui_Hook") -- 动态链接库
--     set_kind("binary")
--     add_files("y_ImGui/*.cpp")
--     add_links("z")                      --链接指令
--     add_linkdirs("D:/Adobe/hihsaiuhdis") -- 链接库目录--失败？保留代码 原因未知





