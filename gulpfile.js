/**
 * author Özgür Çimen on 12.10.2015.
 */
var gulp = require('gulp');
var rename = require('gulp-rename');
var concat = require('gulp-concat');
var sourceDepo = require('source-deposity');
function _targetPath(path) {path = path||"";return "./web/bundles/jetsms/" + path;}
function _sourcePath(path) { path = path||""; return "./src/JetSmsBundle/Resources/public/" + path;}
gulp.task("default", ["wc", "js.concat-project","html.concat-project","resouce-porject"], function () {
    console.log("JetSMS Web Project Organized Started.");
});
gulp.task("wc", function () {    
    gulp.watch([_sourcePath("js/**/*.js"),_sourcePath("libs/**/*.js")], ['js.concat-project']);
    gulp.watch(_sourcePath("l10n/**/*.*"), ['resouce-porject']);
    gulp.watch(_sourcePath("tpl/**/*.html"), ['html.concat-project']);
    gulp.watch(_sourcePath("libs/**/*.*"), ['resouce-porjectlib']);
});
gulp.task("html.concat-project",function(){
	return gulp.src(_sourcePath("tpl/**/*.html"))
	.pipe(gulp.dest(_targetPath("tpl")));
});
gulp.task("resouce-porject",function(){
	return gulp.src(_sourcePath("l10n/**/*.*"))
	.pipe(gulp.dest(_targetPath("l10n")));
});
gulp.task("resouce-porjectlib",function(){
    return gulp.src(_sourcePath("libs/**/*.*"))
    .pipe(gulp.dest(_targetPath("libs")));
});
gulp.task("js.concat-project", function () {
    return gulp.src(sourceDepo.pSrc(_sourcePath()))
        .pipe(concat({path: 'project.js', stat: {mode: 0666}}))
        .pipe(rename('app.min.js'))
        .pipe(gulp.dest(_targetPath()));
});