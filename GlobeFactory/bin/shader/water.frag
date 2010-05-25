uniform sampler2D u_tex1;
uniform sampler2D u_tex2;
uniform float 	  u_time;

void main(void)
{
	vec3 noise;
	vec2 displacement;
	
	displacement = gl_TexCoord[0].st;
	displacement.x += u_time * 0.05;
	displacement.y -= u_time * 0.05;

	noise = normalize(texture2D(u_tex2,displacement.xy * 0.5)).xyz;
	noise = (noise * 2.0 - 1.0) * 0.035;

	gl_FragColor = texture2D(u_tex1, gl_TexCoord[0].st + noise.xy);
	gl_FragColor.a = 0.9;
}

