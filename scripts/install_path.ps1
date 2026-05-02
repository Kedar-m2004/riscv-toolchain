$toolsPath = "C:\tools"

$userPath = [Environment]::GetEnvironmentVariable("Path", "User")

if ($userPath -notlike "*$toolsPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$userPath;$toolsPath", "User")
    Write-Host "Added C:\tools to User PATH."
}
else {
    Write-Host "C:\tools already exists in User PATH."
}
