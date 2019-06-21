namespace Core {

	//OpenGL versions
	struct ContextInfo
	{
		int major_version, minor_version;
		bool core;

		ContextInfo()//default
		{
			major_version = 3;
			minor_version = 3;
			core = true;
		}

		ContextInfo(int major_version, int minor_version, bool core)
		{
			this->major_version = major_version;
			this->minor_version = minor_version;
			this->core = core;
		}

		//just like windowInfo.h
		//implement copy constructor
		//implement assignment operator
		//these implementations are optional because are special functions
	  //<a class="vglnk" href="http://en.wikipedia.org/wiki/Special_member_functions" rel="nofollow"><span>http</span><span>://</span><span>en</span><span>.</span><span>wikipedia</span><span>.</span><span>org</span><span>/</span><span>wiki</span><span>/</span><span>Special</span><span>_</span><span>member</span><span>_</span><span>functions</span></a>
	};
}