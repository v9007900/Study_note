add_rules("mode.debug", "mode.release")

-- target("string")                             -- hstring 项目
--     set_kind("binary")                         -- exe程序
--     add_files("string/*.cpp")                   -- 编译目标目录



target("Hook")                             -- imgui_DLL
    set_kind("shared")                     -- 动态链接库
    add_files("imGui_DLL/*.cpp")              -- 编译目标目录
    add_files("imGui_DLL/imGui/*.cpp") 
    add_files("imGui_DLL/include/*.cpp") 

    -- target("Hook")                             -- imgui_GL
    -- set_kind("binary")                         -- exe程序
    -- add_files("imGui_GL/imGui/*.cpp")              -- 编译目标目录
    -- add_linkdirs("imGui_GL/imGui/API/GLEW")
    -- add_links("glew32")
    -- add_linkdirs("imGui_GL/imGui/API/GLFW")
    -- add_links("glfw3")
    -- add_files("imGui_GL/*.cpp")              -- 编译目标目录






    
    -- add_linkdirs("E:/Git/UnrealEngine/Engine/Source/ThirdParty/Windows/DirectX/Lib/x64/") -- 链接库目录
    -- add_links("d3d11") --库名称




-- target("Hook")                             -- 默认配置
--     set_kind("shared")                     -- DLL程序
--     add_files("string/*.cpp")              -- 编译目标目录


-- target("ImGui_Hook") -- 动态链接库
--     set_kind("binary")
--     add_files("y_ImGui/*.cpp")
--     add_links("z")                      --链接指令
--     add_linkdirs("D:/Adobe/hihsaiuhdis") -- 链接库目录--失败？保留代码 原因未知





