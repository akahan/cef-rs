use std::{env, fs, path::Path};

fn main() {
    println!("cargo::rerun-if-env-changed=CEF_PATH");
    println!("cargo::rustc-check-cfg=cfg(cef_legacy)");

    let Ok(cef_path) = env::var("CEF_PATH") else {
        return;
    };

    let version_header = Path::new(&cef_path).join("include/cef_version.h");
    let Ok(version) = fs::read_to_string(version_header) else {
        return;
    };

    if version
        .lines()
        .any(|line| line.trim() == "#define CEF_VERSION_MAJOR 3")
    {
        println!("cargo::rustc-cfg=cef_legacy");
    }
}
