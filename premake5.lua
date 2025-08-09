workspace("BetterButBadRaytraiser")
configurations({ "Debug", "Release" })
architecture("x64")

project("Raytracer")
kind("ConsoleApp")
language("C++")
cppdialect("C++20")
targetdir("bin/%{cfg.buildcfg}")

files({
	"src/**.h",
	"src/**.cpp",
})

includedirs({
	"src",
	-- Путь к SFML (замени на свой)
	"/usr/include/SFML",
})

links({
	"sfml-graphics",
	"sfml-window",
	"sfml-system",
})

filter("configurations:Debug")
defines({ "DEBUG" })
symbols("On")

filter("configurations:Release")
defines({ "NDEBUG" })
optimize("On")
